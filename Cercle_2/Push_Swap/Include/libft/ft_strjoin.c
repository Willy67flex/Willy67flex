/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:49:58 by whollebe          #+#    #+#             */
/*   Updated: 2025/10/09 17:03:37 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = -1;
	size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	result = malloc(sizeof(*result) * (size + 1));
	if (!result)
		return (NULL);
	while (s1[++j])
		result[i++] = s1[j];
	j = -1;
	while (s2[++j])
		result[i++] = s2[j];
	result[i] = '\0';
	return (result);
}
