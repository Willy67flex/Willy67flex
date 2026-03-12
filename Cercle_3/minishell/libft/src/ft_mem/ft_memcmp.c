/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:02:36 by ele-moig          #+#    #+#             */
/*   Updated: 2025/10/08 15:58:10 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char str1[] = "Hello les gars  du sud";
// 	char str2[] = "Hello les gars";
// 	size_t len = ft_strlen(str1);
// 	int result = ft_memcmp(str1, str2, len);
// 	int testresult = memcmp(str1, str2, len);
// 	printf("%d\n", result);
// 	printf("%d\n", testresult);
// }