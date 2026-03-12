/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:36:35 by whollebe          #+#    #+#             */
/*   Updated: 2026/02/27 14:23:15 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env(t_data *data)
{
	t_env	*node;
	t_env	*runner;

	node = data->env;
	while (node != NULL)
	{
		runner = node->next_env;
		free(node->key);
		free(node->value);
		free(node);
		node = runner;
	}
	data->env = NULL;
	return ;
}

int	find_pos_char(char *str, char c, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strndup(const char *s, int size)
{
	char	*dest;
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	dest = calloc(1, size + 1);
	if (!dest)
		return (NULL);
	while (i < size)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	is_space(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}
