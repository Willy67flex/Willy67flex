/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:34:47 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/11 11:36:12 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_and_count_env(t_data *data, int key)
{
	t_env	*tmp;
	int		count;

	tmp = data->env;
	count = 0;
	while (tmp)
	{
		if (tmp->value != NULL && tmp->flag == 0)
		{
			if (key == 0)
				printf("%s=%s\n", tmp->key, tmp->value);
			count++;
		}
		tmp = tmp->next_env;
	}
	return (count);
}

void	env_add_back(t_env **head, t_env *new_node)
{
	t_env	*curr;

	if (!head || !new_node)
		return ;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	curr = *head;
	while (curr->next_env != NULL)
		curr = curr->next_env;
	curr->next_env = new_node;
}

t_env	*new_env_node(char *str)
{
	t_env	*node;
	int		i;

	i = 0;
	node = ft_calloc(1, sizeof(t_env));
	if (!node)
		return (NULL);
	i = find_pos_char(str, '=', ft_strlen(str));
	node->key = ft_strndup(str, i);
	if (!node->key)
		return (free(node), NULL);
	node->value = ft_strdup(&str[i + 1]);
	if (!node->value)
		return (free(node->key), free(node), NULL);
	node->next_env = NULL;
	node->print = 0;
	return (node);
}

int	init_env(t_data *data, char **env)
{
	int		i;
	t_env	*node;

	i = 0;
	data->env = NULL;
	while (env[i])
	{
		node = new_env_node(env[i]);
		if (!node)
			exit(free_all(data, 1));
		env_add_back(&data->env, node);
		i++;
	}
	node = add_question_mark_node(data);
	if (!node)
		exit(free_all(data, 1));
	env_add_back(&data->env, node);
	check_env(data);
	return (0);
}
