/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:03:31 by whollebe          #+#    #+#             */
/*   Updated: 2025/10/09 17:04:12 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	int		j;
	size_t	n;
	size_t	nn;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	n = len;
	while (big[i] != '\0' && n != 0)
	{
		j = 0;
		nn = n;
		while (big[i + j] == little[j] && little[j] != '\0' && len-- != 0
			&& nn-- != 0)
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
		n--;
	}
	big = NULL;
	return ((char *)big);
}
