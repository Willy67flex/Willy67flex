/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:43:45 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/11 14:58:24 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_value(char *str, int start, int len_key, t_data *data)
{
	char	*key;
	char	*env_val;
	t_env	*node;

	key = ft_strndup(&str[start + 1], len_key);
	if (!key)
		exit(free_all(data, 1));
	node = get_env_node(data->env, key);
	free(key);
	if (node && node->value)
		env_val = ft_strdup(node->value);
	else
		env_val = ft_strdup("");
	if (!env_val)
		exit(free_all(data, 1));
	return (env_val);
}

int	find_dollar_inside(char *str, int start, int end)
{
	int	i;

	i = start + 1;
	while (i < start + end)
	{
		if (str[i] == '$' && str[i + 1] != '\0' && str[i + 1] != '"'
			&& str[i + 1] != ' ')
			return (i);
		i++;
	}
	return (-1);
}

int	scan_arg(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == 39 || str[i] == '"' || str[i] == '$')
			return (1);
	return (0);
}

int	find_the_other_quote(char *str, char c)
{
	int	i;

	i = 0;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}

int	check_key(char *key)
{
	int	i;

	i = 0;
	if (!((key[i] >= 'A' && key[i] <= 'Z') || (key[i] >= 'a' && key[i] <= 'z')
			|| key[i] == '_'))
		return (1);
	i++;
	while (key[i])
	{
		if (!((key[i] >= 'A' && key[i] <= 'Z')
				|| (key[i] >= 'a' && key[i] <= 'z') || key[i] == '_'
				|| (key[i] >= '0' && key[i] <= '9')))
			return (i);
		i++;
	}
	return (i);
}
