/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:45:39 by ele-moig          #+#    #+#             */
/*   Updated: 2025/10/30 14:25:30 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	lens1;
	size_t	lens2;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	newstr = malloc(lens1 + lens2 + 1);
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1, lens1 + 1);
	ft_strlcat(newstr, s2, lens1 + lens2 + 1);
	return (newstr);
}

// int	main(void)
// {
// 	char const str1[] = "tripouille";
// 	char const str2[] = "42";
// 	printf("%s", ft_strjoin(str1, str2));
// }