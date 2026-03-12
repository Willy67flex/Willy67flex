/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:21:58 by ele-moig          #+#    #+#             */
/*   Updated: 2025/10/08 15:58:46 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*hay;
	unsigned char	needle;
	size_t			i;

	hay = (unsigned char *)s;
	needle = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (hay[i] == needle)
			return (&hay[i]);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char str1[] = "Hello les gars  du sud";
// 	int needle = 108;
// 	size_t len = 10;
// 	unsigned char *result = memchr(str1, needle, len);
// 	unsigned char *testresult = ft_memchr(str1, needle, len);
// 	printf("%s\n", result);
// 	printf("%s\n", testresult);
// }