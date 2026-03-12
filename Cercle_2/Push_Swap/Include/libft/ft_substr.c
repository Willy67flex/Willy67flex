/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:38:53 by whollebe          #+#    #+#             */
/*   Updated: 2025/10/09 17:04:26 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int			i;
	char		*str;
	const char	*str1;

	i = 0;
	str1 = s;
	if ((size_t)start >= ft_strlen((char *)s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	if (!s)
		return (NULL);
	str = malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	while (str1[start] && len-- != 0)
		str[i++] = str1[start++];
	str[i] = '\0';
	return ((char *)str);
}
