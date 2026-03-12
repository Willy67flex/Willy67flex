/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:51:28 by whollebe          #+#    #+#             */
/*   Updated: 2025/11/17 13:37:30 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
