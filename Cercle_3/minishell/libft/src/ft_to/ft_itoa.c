/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:07:46 by ele-moig          #+#    #+#             */
/*   Updated: 2025/10/08 16:03:14 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intsize(int nbr)
{
	int			count;
	long int	nb;

	count = 1;
	nb = nbr;
	if (nb < 0)
	{
		nb = -nb;
		count++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int			size;
	int			i;
	long int	nb;
	char		*arr;

	nb = n;
	i = 1;
	size = ft_intsize(nb);
	arr = malloc(size + 1);
	if (!arr)
		return (0);
	if (nb < 0)
	{
		arr[0] = '-';
		nb = -nb;
	}
	while (nb > 9)
	{
		arr[size - i] = (nb % 10) + '0';
		nb = nb / 10;
		i++;
	}
	arr[size - i] = nb + '0';
	arr[size] = '\0';
	return (arr);
}

// int	main(void)
// {
// 	printf("%s", ft_itoa(-12555));
// }