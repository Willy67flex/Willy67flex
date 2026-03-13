/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:58:51 by ele-moig          #+#    #+#             */
/*   Updated: 2026/03/11 09:40:12 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*array;

	array = (void *)malloc(count * size);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, count * size);
	return (array);
}

// int	main(void)
// {
// 	int *ptr = (int *)ft_calloc(-5, -5);
// 	int *test = (int *)calloc(-5 , -5);
// 	printf("%p", ft_calloc(2147483647, 2147483647));
// 	int i = 0;
// 	int j = 0;
// 	while (i < 5)
// 	{
// 		printf("%d ", ptr[i]);
// 		i++;
// 	}
// 	while (j < 5)
// 	{
// 		printf("%d ", test[j]);
// 		j++;
// 	}
// 	if (ptr == NULL)
// 	{
// 		printf("%s", "error");
// 	}
// 		if (test == NULL);
// 	{
// 		printf("%s", "error");
// 	}
// 	return 0;
// }