/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:34:33 by ele-moig          #+#    #+#             */
/*   Updated: 2025/10/14 12:36:44 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printnbr_base(int nbr, char *base, int *count)
{
	long	baselen;
	long	nb;

	nb = nbr;
	baselen = ft_strlen(base);
	if (nb < 0)
	{
		ft_printchar('-', count);
		nb = -nb;
	}
	if (nb >= baselen)
		ft_printnbr_base(nb / baselen, base, count);
	ft_printchar(base[(nb % baselen)], count);
}
