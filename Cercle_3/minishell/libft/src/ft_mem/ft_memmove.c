/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:21:41 by ele-moig          #+#    #+#             */
/*   Updated: 2025/10/08 15:57:37 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*destination;
	char	*source;

	destination = (char *)dest;
	source = (char *)src;
	if (destination < source)
	{
		while (n--)
			*destination++ = *source++;
	}
	else if (destination > source)
	{
		while (n--)
			destination[n] = source[n];
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
// 	memmove(str, str2, 10*sizeof(char));
// 	ft_memmove(test, test2, 10*sizeof(char));
// 	printf("%s\n", str);
// 	printf("%s\n", test);
// }