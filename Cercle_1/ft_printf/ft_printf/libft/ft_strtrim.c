/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:30:05 by whollebe          #+#    #+#             */
/*   Updated: 2025/10/09 17:04:22 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_char(char c, char *set)
{
	size_t		i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		size;
	int		p;
	char	*result;

	i = 0;
	j = 0;
	p = 0;
	size = ft_strlen((char *)s1) - 1;
	if ((!(s1)) || (!(set)))
		return (NULL);
	while (s1[i] && check_char(s1[i], (char *)set) == 1)
		i++;
	while (size >= i && check_char(s1[size], (char *)set) == 1)
		size--;
	result = malloc(sizeof(char) * (size - i + 2));
	if (!result)
		return (NULL);
	j = i;
	while (j <= size)
		result[p++] = s1[j++];
	result[p] = '\0';
	return (result);
}
