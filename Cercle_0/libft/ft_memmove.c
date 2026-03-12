/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:17:21 by whollebe          #+#    #+#             */
/*   Updated: 2025/10/09 17:03:05 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_else(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destination;
	const char	*source;

	destination = dest;
	source = src;
	if (!dest && !src)
		return (NULL);
	if (destination > source)
	{
		while (n > 0)
		{
			n--;
			destination[n] = source[n];
		}
	}
	ft_else(destination, source, n);
	return ((void *)destination);
}
