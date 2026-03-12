/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignment_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:33:16 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/11 11:33:03 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_if_built_in(char *str)
{
	if (ft_strcmp(str, "export") == 0)
		return (1);
	if (ft_strcmp(str, "unset") == 0)
		return (1);
	if (ft_strcmp(str, "pwd") == 0)
		return (1);
	if (ft_strcmp(str, "env") == 0)
		return (1);
	if (ft_strcmp(str, "cd") == 0)
		return (1);
	if (ft_strcmp(str, "echo") == 0)
		return (1);
	if (ft_strcmp(str, "exit") == 0)
		return (1);
	return (0);
}

int	is_valid_assignment(char *str)
{
	char	*key;
	int		equal_pos;

	equal_pos = find_pos_char(str, '=', ft_strlen(str));
	if (equal_pos == -1)
		return (0);
	key = ft_strndup(str, equal_pos);
	if (!key)
		return (2);
	if (check_is_a_valide_key(key, str) == 1)
	{
		free(key);
		return (0);
	}
	free(key);
	return (1);
}

int	check_assignment(char **str)
{
	int	i;
	int	key;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		key = is_valid_assignment(str[i]);
		if (key == 2)
			return (-1);
		if (!key)
			break ;
		i++;
	}
	return (i);
}

int	tab_len(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		i++;
	return (i);
}

char	**tab_dup(char **str)
{
	int		i;
	char	**new_str;

	if (!str)
		return (NULL);
	new_str = malloc(sizeof(char *) * (tab_len(str) + 1));
	if (!new_str)
		return (NULL);
	i = -1;
	while (str[++i])
	{
		new_str[i] = ft_strdup(str[i]);
		if (!new_str[i])
		{
			while (--i >= 0)
				free(new_str[i]);
			free(new_str);
			return (NULL);
		}
	}
	new_str[i] = NULL;
	return (new_str);
}
