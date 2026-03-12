/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:24:12 by ele-moig          #+#    #+#             */
/*   Updated: 2026/03/11 14:03:57 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_child_prep(t_data *data, t_cmd_node *run)
{
	setup_execution_signals();
	if (run->assignment != NULL)
	{
		apply_assignments(data, run, 1);
		free_tab(data->tab);
		data->tab = env_to_tab(data);
		if (!data->tab)
			exit(free_all(data, 1));
	}
	if (!run->args || !run->args[0])
	{
		free_all(data, 0);
		exit(0);
	}
}

int	short_circuit(t_data *dt, t_cmd_node *run)
{
	int	flag;

	flag = 0;
	if (dt->cmd_node_nbr != 1)
		return (0);
	if (run->assignment && (!run->args || !run->args[0]))
		return (apply_assignments(dt, run, 0), 1);
	if (run->args && run->args[0] && check_short_circuit(run))
	{
		if (run->assignment)
		{
			flag = 1;
			if (!ft_strcmp(run->args[0], "export")
				|| !ft_strcmp(run->args[0], "unset")
				|| !ft_strcmp(run->args[0], "exit"))
				flag = 0;
			apply_assignments(dt, run, 0);
		}
		return (short_circuit_handler(dt, run, flag), 1);
	}
	return (0);
}

void	first_cmd(t_data *data, t_cmd_node *runner, int *prev_fd, pid_t *pid)
{
	int	fd[2];

	if (short_circuit(data, runner))
		return ;
	pipe(fd);
	*pid = fork();
	if (*pid == 0)
	{
		exec_child_prep(data, runner);
		if (runner->fd_in != -2)
			dup2(runner->fd_in, 0);
		if (runner->fd_out != -2)
			dup2(runner->fd_out, 1);
		else if (runner->next_cmd)
			dup2(fd[1], 1);
		selec_exec(data, runner);
	}
	else
		parent_fd_handler(fd, prev_fd);
}

void	mid_cmds(t_data *data, t_cmd_node *runner, int *prev_fd, pid_t *pid)
{
	int	fd[2];

	pipe(fd);
	*pid = fork();
	if (*pid == 0)
	{
		exec_child_prep(data, runner);
		child_fd_handler(runner, prev_fd, fd);
		data->path = find_cmd_path(data, runner->args[0]);
		selec_exec(data, runner);
	}
	else
		parent_fd_handler(fd, prev_fd);
}

void	last_cmd(t_data *data, t_cmd_node *runner, int *prev_fd, pid_t *pid)
{
	*pid = fork();
	if (*pid == 0)
	{
		exec_child_prep(data, runner);
		if (runner->fd_in != -2)
			dup2(runner->fd_in, 0);
		else if (*prev_fd != -2)
			dup2(*prev_fd, 0);
		if (runner->fd_out != -2)
			dup2(runner->fd_out, 1);
		if (*prev_fd != -2)
			close(*prev_fd);
		data->path = find_cmd_path(data, runner->args[0]);
		selec_exec(data, runner);
	}
	else if (*prev_fd != -2)
		close(*prev_fd);
}
