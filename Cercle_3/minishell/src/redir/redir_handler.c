/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 11:48:41 by ele-moig          #+#    #+#             */
/*   Updated: 2026/03/11 14:21:34 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_open_manager(t_cmd_node *cmd_node, t_data *data)
{
	t_redir	*runner;
	int		redir_in_ret;

	redir_in_ret = 0;
	runner = cmd_node->redirection;
	while (runner)
	{
		if (runner->operator == TOKEN_REDIR_OUT
			|| runner->operator == TOKEN_APPEND)
		{
			if (ft_redir_out_handler(cmd_node, runner, data) == 1)
				return (1);
		}
		else
		{
			redir_in_ret = ft_redir_in_handler(cmd_node, runner, data);
			if (redir_in_ret == 1 || redir_in_ret == 2)
				return (redir_in_ret);
		}
		if (runner->next_redir)
			runner = runner->next_redir;
		else
			break ;
	}
	return (0);
}

int	ft_redir_out_handler(t_cmd_node *cmd_node, t_redir *runner, t_data *data)
{
	int		tmp_fd;
	int		err_code;

	err_code = 0;
	tmp_fd = -2;
	if (runner->operator == TOKEN_REDIR_OUT)
		tmp_fd = open(runner->path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (runner->operator == TOKEN_APPEND)
		tmp_fd = open(runner->path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (tmp_fd == -1)
	{
		err_code = errno;
		print_sys_error(runner->path, NULL, err_code);
		data->exit_code = 1;
		return (1);
	}
	else
	{
		if (cmd_node->fd_out != -2)
			close(cmd_node->fd_out);
		cmd_node->fd_out = tmp_fd;
	}
	return (0);
}

int	ft_redir_in_handler(t_cmd_node *cmd_node, t_redir *runner, t_data *data)
{
	int		tmp_fd;
	int		err_code;

	tmp_fd = -2;
	if (runner->operator == TOKEN_REDIR_IN)
		tmp_fd = open(runner->path, O_RDONLY);
	else
		tmp_fd = ft_heredoc(data, runner->path);
	if (tmp_fd == -1)
	{
		err_code = errno;
		return (tmp_fd_err(data, runner, err_code));
	}
	else if (tmp_fd == -3)
	{
		ft_putstr_fd("> ^C\n", 2);
		return (2);
	}
	else
	{
		if (cmd_node->fd_in != -2)
			close(cmd_node->fd_in);
		cmd_node->fd_in = tmp_fd;
	}
	return (0);
}

int	ft_heredoc(t_data *data, char *delim)
{
	pid_t	pid;
	int		fd_read;
	int		fd_write;
	int		err_code;

	err_code = 0;
	setup_mute_signals();
	pid = fork();
	if (pid == 0)
	{
		setup_heredoc_signals();
		fd_write = open("tmp_heredoc", O_CREAT
				| O_WRONLY | O_TRUNC, 0644);
		if (fd_write == -1)
		{
			err_code = errno;
			print_sys_error("heredoc", NULL, err_code);
			exit(1);
		}
		ft_heredoc_wr(fd_write, data, delim);
		close (fd_write);
		exit(0);
	}
	else
		return (wait_redir(&pid, &fd_read, data));
}
