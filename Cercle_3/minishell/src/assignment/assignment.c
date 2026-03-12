/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 10:37:57 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/11 11:32:42 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**update_cmd(char **cmd, int count)
{
	char	**new_cmd;
	int		size;
	int		i;

	i = 0;
	size = (tab_len(cmd) - count);
	new_cmd = malloc(sizeof(char *) * (size + 1));
	if (!new_cmd)
		return (free_tab(cmd), NULL);
	while (cmd[count])
	{
		new_cmd[i] = ft_strdup(cmd[count]);
		if (!new_cmd[i])
		{
			while (--i >= 0)
				free(new_cmd[i]);
			return (free(new_cmd), free_tab(cmd), NULL);
		}
		i++;
		count++;
	}
	new_cmd[i] = NULL;
	free_tab(cmd);
	return (new_cmd);
}

void	update_assignment(t_cmd_node *runner, int size, t_data *data)
{
	int		i;
	char	**cmd;

	i = -1;
	cmd = tab_dup(runner->args);
	if (!cmd)
		exit(free_all(data, 1));
	runner->assignment = malloc(sizeof(char *) * (size + 1));
	if (!runner->assignment)
	{
		ft_free_tab(cmd);
		exit(free_all(data, 1));
	}
	while (++i < size)
	{
		runner->assignment[i] = ft_strdup(cmd[i]);
		if (!runner->assignment[i])
			exit(free_all(data, 1));
	}
	runner->assignment[i] = NULL;
	ft_free_tab(runner->args);
	runner->args = update_cmd(cmd, size);
	if (!runner->args)
		exit(free_all(data, 1));
}

void	assignment(t_data *data)
{
	t_cmd_node	*runner;
	int			count;

	runner = data->cmds;
	while (runner)
	{
		runner->assignment = NULL;
		count = check_assignment(runner->args);
		if (count == -1)
			exit(free_all(data, 1));
		if (count > 0)
			update_assignment(runner, count, data);
		runner = runner->next_cmd;
	}
}
