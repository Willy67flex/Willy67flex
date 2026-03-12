/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:34:29 by whollebe          #+#    #+#             */
/*   Updated: 2025/11/17 13:37:30 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int nbr, char *base, int *count_print)
{
	int		lenbase;
	long	nb;

	nb = nbr;
	lenbase = ft_strlen(base);
	if (nb < 0)
	{
		ft_write_count('-', count_print);
		nb *= -1;
	}
	if (nb >= lenbase)
	{
		ft_putnbr_base(nb / lenbase, base, count_print);
		ft_write_count(base[nb % lenbase], count_print);
	}
	else
		ft_write_count(base[nb % lenbase], count_print);
}
