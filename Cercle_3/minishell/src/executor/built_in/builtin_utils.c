/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:41:33 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/11 13:26:04 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_cmd_built_in(t_data *data, t_cmd_node *runner)
{
	char	*pwd;

	if (!runner->args || !runner->args[0])
		return (0);
	if (ft_strcmp(runner->args[0], "export") == 0)
		return (execute_builtin_export(data, runner), 1);
	if (ft_strcmp(runner->args[0], "unset") == 0)
		return (execut_unset(data, runner, 0), 1);
	if (ft_strcmp(runner->args[0], "pwd") == 0)
		return (pwd = getcwd(NULL, 0), printf("%s\n", pwd), free(pwd), 1);
	if (ft_strcmp(runner->args[0], "env") == 0)
		return (print_and_count_env(data, 0), 1);
	if (ft_strcmp(runner->args[0], "cd") == 0)
		return (ft_cd(data, runner->args), 1);
	if (ft_strcmp(runner->args[0], "echo") == 0)
		return (ft_echo(runner), 1);
	if (ft_strcmp(runner->args[0], "exit") == 0)
		return (ft_exit(data, runner, 1));
	return (0);
}

void	short_circuit_handler(t_data *data, t_cmd_node *runner, int flag)
{
	int	temp_fd[2];

	short_cirtcuit_fd(runner, temp_fd);
	if (ft_strcmp(runner->args[0], "export") == 0)
		execute_builtin_export(data, runner);
	else if (ft_strcmp(runner->args[0], "unset") == 0)
		execut_unset(data, runner, 0);
	else if (ft_strcmp(runner->args[0], "cd") == 0)
		ft_cd(data, runner->args);
	else if (ft_strcmp(runner->args[0], "exit") == 0)
		ft_exit(data, runner, 1);
	close_short_circuit(temp_fd[1], temp_fd[0]);
	if (flag == 1)
		execut_unset(data, runner, 1);
	return ;
}

int	check_short_circuit(t_cmd_node *runner)
{
	if (ft_strcmp(runner->args[0], "export") == 0)
		return (1);
	if (ft_strcmp(runner->args[0], "unset") == 0)
		return (1);
	if (ft_strcmp(runner->args[0], "cd") == 0)
		return (1);
	if (ft_strcmp(runner->args[0], "exit") == 0)
		return (1);
	return (0);
}

void	close_short_circuit(int temp_out, int temp_in)
{
	if (temp_in >= 0)
	{
		dup2(temp_in, 0);
		close(temp_in);
	}
	if (temp_out >= 0)
	{
		dup2(temp_out, 1);
		close(temp_out);
	}
}

void	short_cirtcuit_fd(t_cmd_node *runner, int *temp_fd)
{
	int	temp_out;
	int	temp_in;

	temp_in = -2;
	temp_out = -2;
	if (runner->fd_in != -2)
	{
		temp_in = dup(0);
		dup2(runner->fd_in, 0);
	}
	if (runner->fd_out != -2)
	{
		temp_out = dup(1);
		dup2(runner->fd_out, 1);
	}
	temp_fd[0] = temp_in;
	temp_fd[1] = temp_out;
}
