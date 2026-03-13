/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:51:33 by ele-moig          #+#    #+#             */
/*   Updated: 2025/10/08 15:59:30 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	dest = malloc(ft_strlen(str) + 1);
	if (!dest)
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// int	main(void)
// {
// 	char * string = ft_strdup((char *)"coucou");
// 	char * string2 = ft_strdup((char *)"coucou");
// 	printf("%s\n", string);
// 	printf("%s", string2);
// }