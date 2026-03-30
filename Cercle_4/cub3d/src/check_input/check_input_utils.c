/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 10:54:25 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/24 14:09:28 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	msg_error(char *msg)
{
	ft_printf("Error\n%s\n", msg);
	exit(1);
}

void	clean_newline(char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] == '\n')
			str[j] = '\0';
		j++;
	}
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\n' || line[i] == '\0')
		return (1);
	return (0);
}

char	*extract_path(char *line, int skip)
{
	char	*path;
	int		i;
	int		j;

	i = skip;
	j = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	path = ft_strdup(line + i);
	while (path[j])
	{
		if (path[j] == '\n')
			path[j] = '\0';
		j++;
	}
	return (path);
}
