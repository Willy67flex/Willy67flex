/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:00:50 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/11 14:16:31 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_good_path(char **str, char *cmd)
{
	int		i;
	int		j;
	int		p;
	char	*path;

	i = 0;
	while (str[i])
	{
		path = malloc(sizeof(char) * (ft_strlen(str[i]) + ft_strlen(cmd) + 2));
		p = -1;
		j = -1;
		while (str[i][++p])
			path[p] = str[i][p];
		path[p] = '/';
		while (cmd[++j])
			path[++p] = cmd[j];
		path[++p] = '\0';
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

char	*find_cmd_path(t_data *data, char *cmd)
{
	t_env	*runner;
	char	**tmp;
	char	*path;

	path = NULL;
	tmp = NULL;
	runner = data->env;
	if (ft_strchr(cmd, '/') && access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	while (runner)
	{
		if (ft_strncmp("PATH", runner->key, 4) == 0)
			tmp = ft_split(runner->value, ':');
		runner = runner->next_env;
	}
	if (tmp != NULL)
	{
		path = find_good_path(tmp, cmd);
		free_tab(tmp);
	}
	return (path);
}

char	**env_to_tab(t_data *data)
{
	t_env	*runner;
	char	**tab;
	int		i;

	runner = data->env;
	i = 0;
	tab = malloc(sizeof(char *) * (print_and_count_env(data, 1) + 1));
	if (!tab)
		return (NULL);
	while (runner != NULL)
	{
		if (runner->value == NULL || runner->flag == 1)
			runner = runner->next_env;
		else
		{
			tab[i] = join_key_value(runner);
			if (!tab[i])
				return (free_tab(tab), NULL);
			i++;
			runner = runner->next_env;
		}
	}
	tab[i] = NULL;
	return (tab);
}

int	ft_executor(t_data *data)
{
	t_cmd_node	*runner;

	runner = data->cmds;
	data->tab = env_to_tab(data);
	if (!data->tab)
		exit(free_all(data, 1));
	ft_exec_handler(data, runner);
	return (0);
}

void	ft_exec_handler(t_data *data, t_cmd_node *runner)
{
	int			prev_fd;
	pid_t		pid;
	int			i;

	i = 1;
	prev_fd = -2;
	pid = -2;
	setup_mute_signals();
	first_cmd(data, runner, &prev_fd, &pid);
	if (runner->next_cmd)
		runner = runner->next_cmd;
	while (i < data->cmd_node_nbr - 1)
	{
		mid_cmds(data, runner, &prev_fd, &pid);
		i++;
		if (runner->next_cmd)
			runner = runner->next_cmd;
	}
	if (i == data->cmd_node_nbr - 1 && data->cmd_node_nbr > 1)
		last_cmd(data, runner, &prev_fd, &pid);
	wait_children(pid, data, data->cmd_node_nbr);
	setup_interactive_signals();
}
