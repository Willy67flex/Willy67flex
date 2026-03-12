/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:19:16 by whollebe          #+#    #+#             */
/*   Updated: 2025/11/28 15:48:58 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdint.h>
#include "libft.h"

char	*ft_strjoin_and_free(char *s1, const char *s2)
{
	char	*new_str;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	if (!s1)
		len1 = 0;
	else
		len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 > SIZE_MAX - len2 - 1)
		return (free(s1), NULL);
	new_str = malloc(len1 + len2 + 1);
	if (!new_str)
		return (free(s1), NULL);
	i = -1;
	while (++i < len1)
		new_str[i] = s1[i];
	j = -1;
	while (++j < len2)
		new_str[i++] = s2[j];
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}

int	ft_strchr_found(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_extract_line(const char *storage)
{
	char	*line;
	int		i;

	i = 0;
	if (!storage || storage[0] == '\0')
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_update_storage(char *storage)
{
	char	*new_storage;
	int		i;
	int		j;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\0')
		return (free(storage), NULL);
	i++;
	new_storage = malloc(ft_strlen(&storage[i]) + 1);
	if (!new_storage)
		return (free(storage), NULL);
	j = 0;
	while (storage[i])
		new_storage[j++] = storage[i++];
	new_storage[j] = '\0';
	free(storage);
	return (new_storage);
}
