/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:57:29 by ele-moig          #+#    #+#             */
/*   Updated: 2025/10/08 15:56:56 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t						i;
	unsigned char				*set;
	const unsigned char			*source;

	i = 0;
	set = dest;
	source = src;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		set[i] = source[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char str[] = "Hello la team des gens de 42";
// 	char str2[] = "bonjour";
// 	char test[] = "Hello la team des gens de 42";
// 	char test2[] = "bonjour";
// 	int a = 20;
// 	int b = 10;
// 	int a2 = 20;
// 	int b2 = 10;
// 	memcpy(&a, &b, sizeof(int));
// 	ft_memcpy(&a2, &b2, sizeof(int));
// 	printf("%d\n", a);
// 	printf("%d\n", a2);
// }