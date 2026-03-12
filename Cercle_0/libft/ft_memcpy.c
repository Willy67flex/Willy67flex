/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:58:49 by whollebe          #+#    #+#             */
/*   Updated: 2025/10/09 17:03:00 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*destination;
	const char	*source;

	i = 0;
	destination = dest;
	source = src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return ((void *)destination);
}
