/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:51:35 by whollebe          #+#    #+#             */
/*   Updated: 2025/10/09 17:02:39 by whollebe         ###   ########.fr       */
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
	char		*result;

	nb = n;
	i = 1;
	size = ft_intsize(nb);
	result = malloc(size + 1);
	if (!result)
		return (0);
	if (nb < 0)
	{
		result[0] = '-';
		nb = -nb;
	}
	while (nb > 9)
	{
		result[size - i] = (nb % 10) + '0';
		nb = nb / 10;
		i++;
	}
	result[size - i] = nb + '0';
	result[size] = '\0';
	return (result);
}
