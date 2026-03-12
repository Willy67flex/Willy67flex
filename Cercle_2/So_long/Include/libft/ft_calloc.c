/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:02:08 by whollebe          #+#    #+#             */
/*   Updated: 2025/10/09 17:02:10 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	char	*ptr;
	size_t	i;

	i = 0;
	total = nmemb * size;
	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	ptr = malloc(sizeof(char) * (total));
	if (!(ptr))
		return (NULL);
	while (i < total)
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}
