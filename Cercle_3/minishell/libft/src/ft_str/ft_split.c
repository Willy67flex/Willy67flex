/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:36:46 by ele-moig          #+#    #+#             */
/*   Updated: 2025/12/10 15:11:39 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			words++;
		if (s[i] != c && i > 0 && s[i - 1] == c)
			words++;
		i++;
	}
	return (words);
}

static int	word_length(const char *s, char c, int i)
{
	int	result;

	result = 0;
	while (s[result + i] && s[result + i] != c)
		result++;
	return (result);
}

static void	*ft_free(char **arr, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	int				sizeofword;
	size_t			arrindex;
	char			**arr;

	i = 0;
	arrindex = 0;
	arr = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!arr)
		return (0);
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			sizeofword = word_length(s, c, i);
			arr[arrindex] = malloc(sizeofword + 1);
			if (!arr[arrindex])
				ft_free(arr, (count_words(s, c) + 1));
			ft_strlcpy(arr[arrindex], s + i, sizeofword + 1);
			arrindex++;
		}
		i++;
	}
	arr[arrindex] = 0;
	return (arr);
}

// int main(void)
// {
// 	char **arr = ft_split("", 'z');
// 	// printf("%d\n", count_words("Hey,la team,les gens", ','));
// 	printf("%s\n", arr[0]);
// 	printf("%s\n", arr[1]);
// 	printf("%s\n", arr[2]);
// }