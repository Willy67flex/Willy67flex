/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:43:45 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/05 18:46:54 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*remove_quotes(char *str, int start, int end)
{
	char	*new_str;
	int		i;
	int		j;

	new_str = malloc(sizeof(char) * (ft_strlen(str) - 1));
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (j < start)
		new_str[i++] = str[j++];
	j++;
	while (j < start + end)
		new_str[i++] = str[j++];
	j++;
	while (str[j])
		new_str[i++] = str[j++];
	new_str[i] = '\0';
	return (new_str);
}

int	process_squotes(char **str, int *i, t_data *data)
{
	int		end;
	char	*new_str;

	end = find_the_other_quote(&(*str)[*i], 39);
	if (end == -1)
		return (data->exit_code = 2, 1);
	new_str = remove_quotes(*str, *i, end);
	free(*str);
	if (!new_str)
		exit(free_all(data, 1));
	*str = new_str;
	*i += (end - 1);
	return (0);
}

int	process_dquotes(char **str, int *i, t_data *data)
{
	int		end;
	int		dollar;
	char	*new_str;

	end = find_the_other_quote(&(*str)[*i], '"');
	if (end == -1)
		return (data->exit_code = 2, 1);
	dollar = find_dollar_inside(*str, *i, end);
	if (dollar != -1)
	{
		new_str = update_dollar(*str, dollar,
				check_key(&(*str)[dollar + 1]), data);
		free(*str);
		if (!new_str)
			exit(free_all(data, 1));
		*str = new_str;
		return (0);
	}
	new_str = remove_quotes(*str, *i, end);
	free(*str);
	if (!new_str)
		exit(free_all(data, 1));
	*str = new_str;
	*i += (end - 1);
	return (0);
}
