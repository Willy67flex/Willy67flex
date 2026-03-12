/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:35:07 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/11 11:39:58 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*add_question_mark_node(t_data *data)
{
	t_env	*node;

	node = ft_calloc(1, sizeof(t_env));
	if (!node)
		return (NULL);
	node->flag = 1;
	node->key = ft_strdup("?");
	if (!node->key)
		return (free(node), NULL);
	node->value = ft_itoa(data->exit_code);
	if (!node->value)
		return (free(node->key), free(node), NULL);
	node->next_env = NULL;
	return (node);
}

char	*build_env_pwd(char *str, t_data *data)
{
	int		i;
	int		j;
	char	*new_str;
	char	*path;

	path = getcwd(NULL, 0);
	new_str = malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(str) + 1));
	if (!new_str)
	{
		free(path);
		exit(free_all(data, 2));
	}
	i = -1;
	while (str[++i])
		new_str[i] = str[i];
	j = -1;
	while (path[++j])
	{
		new_str[i] = path[j];
		i++;
	}
	new_str[i] = '\0';
	free(path);
	return (new_str);
}
