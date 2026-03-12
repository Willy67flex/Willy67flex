/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:21:55 by whollebe          #+#    #+#             */
/*   Updated: 2025/10/09 17:03:25 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_len_split(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	ft_count_split(const char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
			j++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (j);
}

static void	ft_free(char **result, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static char	*fill_word(char const *s, char c, int *i)
{
	int		len;
	int		j;
	char	*word;

	len = ft_str_len_split(&s[*i], c);
	word = malloc(sizeof(char) * len + 1);
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
		word[j++] = s[(*i)++];
	word[j] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = malloc(sizeof(char *) * (ft_count_split(s, c) + 1));
	if (!result)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		result[j] = fill_word(s, c, &i);
		if (!result[j])
			return (ft_free(result, j), NULL);
		j++;
	}
	result[j] = NULL;
	return (result);
}
