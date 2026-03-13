/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:18:17 by ele-moig          #+#    #+#             */
/*   Updated: 2025/10/08 15:50:43 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	char			*toreturn;
	unsigned char	testchar;

	i = 0;
	toreturn = NULL;
	testchar = c;
	if (testchar == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (i < ft_strlen(s))
	{
		if (s[i] == testchar)
			toreturn = (char *)&s[i];
		i++;
	}
	return (toreturn);
}

// int	main(void)
// {
// 	const char s[] = "teste";
// 	printf("%s\n", ft_strrchr(s, '\0'));
// 	printf("%s", strrchr(s, '\0'));
// }