/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:43:45 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/11 14:55:09 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_dollar(char **str, int *i, t_data *data)
{
	int		len_key;
	int		len_val;
	char	*val;
	char	*new_str;

	if ((*str)[*i + 1] == ' ' || (*str)[*i + 1] == '\0')
	{
		(*i)++;
		return (0);
	}
	len_key = check_key(&(*str)[*i + 1]);
	val = get_env_value(*str, *i, len_key, data);
	len_val = ft_strlen(val);
	if (len_val == 0)
		return (free(val), 1);
	free(val);
	new_str = update_dollar(*str, *i, len_key, data);
	free(*str);
	if (!new_str)
		exit(free_all(data, 1));
	*str = new_str;
	*i += len_val;
	return (0);
}

char	*update_dollar(char *str, int start, int len_key, t_data *data)
{
	char	*new_s;
	char	*val;
	int		i;
	int		j;

	val = get_env_value(str, start, len_key, data);
	new_s = malloc(sizeof(char) * (ft_strlen(str) - len_key + ft_strlen(val)));
	if (!new_s)
		return (free(val), NULL);
	i = -1;
	while (++i < start)
		new_s[i] = str[i];
	j = -1;
	while (val[++j])
		new_s[i++] = val[j];
	j = start + len_key + 1;
	while (str[j])
		new_s[i++] = str[j++];
	new_s[i] = '\0';
	free(val);
	return (new_s);
}
