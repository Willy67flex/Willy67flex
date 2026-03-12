/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 08:49:21 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/11 11:06:32 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_env_node(t_data *data, char *key, char *value, int nb)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	if (!node)
	{
		free(key);
		free(value);
		return ;
	}
	node->key = key;
	node->value = value;
	node->print = 0;
	if (nb == 1)
		node->flag = 1;
	else
		node->flag = 0;
	node->next_env = NULL;
	env_add_back(&data->env, node);
}

void	extract_key_value(char *s, char **key, char **value)
{
	int	count;

	count = find_pos_char(s, '=', ft_strlen(s));
	if (count == -1)
	{
		*key = ft_strdup(s);
		*value = NULL;
	}
	else
	{
		*key = ft_strndup(s, count);
		*value = ft_strdup(&s[count + 1]);
	}
}
