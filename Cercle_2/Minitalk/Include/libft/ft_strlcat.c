/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:38:16 by whollebe          #+#    #+#             */
/*   Updated: 2025/10/09 17:03:42 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	x;
	size_t	i;
	size_t	j;

	x = ft_strlen((char *)src) + ft_strlen((char *)dst);
	i = 0;
	j = 0;
	if (size <= ft_strlen((char *)dst))
		return (size + ft_strlen((char *)src));
	while ((size - 1) != 0 && dst[i])
	{
		if (size == 0)
			break ;
		i++;
		size--;
	}
	while ((size - 1) != 0 && src[j])
	{
		if (size-- == 0)
			break ;
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (x);
}
