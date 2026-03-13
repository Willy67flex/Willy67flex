/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:19:57 by ele-moig          #+#    #+#             */
/*   Updated: 2025/10/08 15:38:13 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	maxlen;
	size_t	destlen;
	size_t	srclen;

	srclen = ft_strlen(src);
	destlen = ft_strlen(dest);
	maxlen = size - 1;
	i = 0;
	if (destlen > size || size == 0)
		return (size + srclen);
	while (src[i] && (destlen + i) < maxlen)
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (destlen + srclen);
}

// int	main(void)
// {
// 	char dest[30]; memset(dest, 'B', 4);
// 	char dest2[30]; memset(dest2, 'B', 4);
// 	char * src = (char *)"AAAAAAAAA";
// 	dest[0] = 'B';
// 	dest2[0] = 'B';

// 	printf("dest 1:%s\n", dest);
// 	printf("dest 2:%s\n", dest2);
// 	printf("source is :%s\n", src);
// 	ft_strlcat(dest, src, 6);
// 	printf("Strlcat 1:%s\n", dest);
// 	strlcat(dest2, src, 6);
// 	printf("Strlcat 2:%s\n", dest2);
// }