/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:40:22 by ele-moig          #+#    #+#             */
/*   Updated: 2025/10/08 15:59:12 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*src;
	size_t			i;

	src = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		src[i] = '\0';
		i++;
	}
}

// int	main(void)
// {
// 	char teststr[] = "Hey les gens";
// 	size_t size = 4;
// 	printf("%s\n", teststr);
// 	ft_bzero(teststr, size);
// 	printf("%s", teststr);
// }