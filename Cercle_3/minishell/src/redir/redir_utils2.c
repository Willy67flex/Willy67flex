/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:03:13 by ele-moig          #+#    #+#             */
/*   Updated: 2026/03/11 14:21:29 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tmp_fd_err(t_data *data, t_redir *runner, int err_code)
{
	print_sys_error(runner->path, NULL, err_code);
	data->exit_code = 1;
	return (1);
}

int	wait_redir(pid_t *pid, int *fd_read, t_data *data)
{
	int	wstatus;

	waitpid(*pid, &wstatus, 0);
	setup_interactive_signals();
	if (WIFEXITED(wstatus))
	{
		if (WEXITSTATUS(wstatus) == 0)
		{
			*fd_read = exit_handler_zero(fd_read);
			data->exit_code = WEXITSTATUS(wstatus);
			return (*fd_read);
		}
		else
		{
			data->exit_code = WEXITSTATUS(wstatus);
			return (-1);
		}
	}
	else if (WIFSIGNALED(wstatus))
	{
		data->exit_code = 128 + WTERMSIG(wstatus);
		unlink("tmp_heredoc");
		return (-3);
	}
	return (0);
}

int	exit_handler_zero(int *fd_read)
{
	*fd_read = open("tmp_heredoc", O_RDONLY);
	if (*fd_read == -1)
	{
		unlink("tmp_heredoc");
		return (-1);
	}
	unlink("tmp_heredoc");
	return (*fd_read);
}
