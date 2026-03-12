/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_intsize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:21:36 by whollebe          #+#    #+#             */
/*   Updated: 2025/11/17 13:37:30 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_intsize(unsigned int nbr)
{
	int			count;

	count = 1;
	while (nbr > 9)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}
