/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:36:20 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/11 13:50:33 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env_node(t_env *node)
{
	if (!node)
		return ;
	if (node->key)
		free(node->key);
	if (node->value)
		free(node->value);
	free(node);
}

void	ft_unset(t_data *data, char *key)
{
	t_env	*node;
	t_env	*prev;

	if (data->env == NULL)
		return ;
	prev = data->env;
	node = data->env->next_env;
	if (ft_strcmp(prev->key, key) == 0)
	{
		data->env = node;
		free_env_node(prev);
		return ;
	}
	while (node != NULL)
	{
		if (ft_strcmp(node->key, key) == 0)
		{
			prev->next_env = node->next_env;
			free_env_node(node);
			return ;
		}
		prev = prev->next_env;
		node = node->next_env;
	}
}

void	unset_assignment(t_data *data, t_cmd_node *runner)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	while (runner->assignment[i] != NULL)
	{
		extract_key_value(runner->assignment[i], &key, &value);
		ft_unset(data, key);
		free(key);
		free(value);
		i++;
	}
}

void	execut_unset(t_data *data, t_cmd_node *runner, int flag)
{
	int			i;
	char		*key;
	char		*value;

	if (flag == 1)
		unset_assignment(data, runner);
	else
	{
		i = 1;
		while (runner->args[i] != NULL)
		{
			extract_key_value(runner->args[i], &key, &value);
			ft_unset(data, key);
			free(key);
			free(value);
			i++;
		}
	}
}
