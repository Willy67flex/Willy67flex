/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:37:48 by ele-moig          #+#    #+#             */
/*   Updated: 2025/10/08 15:52:04 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*set;

	set = s;
	i = 0;
	while (i < n)
	{
		set[i] = c;
		i++;
	}
	return (s);
}

// int	main(void)
// {
// 	char str[] = "Hello la team des gens de 42";
// 	char str2[] = "Hello la team des gens de 42";
// 	memset(str2 + 5, '.', 8*sizeof(char));
// 	ft_memset(str + 5, '.', 8*sizeof(char));
// 	printf("%s\n", str);
// 	printf("%s\n", str2);
// }