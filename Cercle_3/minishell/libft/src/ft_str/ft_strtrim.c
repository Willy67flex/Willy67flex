/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:36:30 by ele-moig          #+#    #+#             */
/*   Updated: 2025/10/08 16:04:08 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;

	len = ft_strlen(s1);
	start = 0;
	end = len - 1;
	while (s1[start] && (ft_strchr(set, s1[start]) != 0))
		start++;
	while (start < end && (ft_strrchr(set, s1[end]) != 0))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}

// int	main(void)
// {
// 	const char *string = "-----Hello tout asgard---";
// 	const char *testset = "-";
// 	printf("%s\n", ft_strtrim(string, testset));
// }