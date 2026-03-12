/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:56:14 by ele-moig          #+#    #+#             */
/*   Updated: 2026/03/11 14:37:01 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	resolve_path(t_data *data, t_cmd_node *run)
{
	int	err;

	if (ft_slash_in_cmd(run->args[0]) == 1)
	{
		data->path = find_cmd_path(data, run->args[0]);
		if (!data->path)
		{
			print_custom_error(run->args[0], NULL, "command not found");
			free_all(data, 1);
			exit(127);
		}
	}
	else
	{
		data->path = ft_strdup(run->args[0]);
		if (!data->path)
		{
			err = errno;
			print_sys_error(run->args[0], NULL, err);
			free_all(data, 1);
			exit(1);
		}
	}
}

void	handle_exec_error(t_data *data, t_cmd_node *run)
{
	struct stat	err_struct;
	int			err_code;
	int			final_exit_code;

	err_code = errno;
	data->exit_code = 126;
	if (err_code == ENOENT)
		data->exit_code = 127;
	else if (err_code == EACCES)
	{
		stat(data->path, &err_struct);
		if (S_ISDIR(err_struct.st_mode))
			err_code = EISDIR;
	}
	print_sys_error(run->args[0], NULL, err_code);
	final_exit_code = data->exit_code;
	free_all(data, 1);
	exit(final_exit_code);
}

void	selec_exec(t_data *data, t_cmd_node *runner)
{
	int	check;

	check = check_cmd_built_in(data, runner);
	if (check == 1 || check == 2)
	{
		free_all(data, 1);
		exit(data->exit_code);
	}
	else if (check == 0)
	{
		resolve_path(data, runner);
		execve(data->path, runner->args, data->tab);
		handle_exec_error(data, runner);
	}
}

int	ft_slash_in_cmd(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (0);
		i++;
	}
	return (1);
}
