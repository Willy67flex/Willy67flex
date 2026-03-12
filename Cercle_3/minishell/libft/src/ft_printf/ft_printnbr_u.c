/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:59:16 by ele-moig          #+#    #+#             */
/*   Updated: 2025/10/14 12:37:12 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printnbr_u(unsigned int nbr, char *base, int *count)
{
	unsigned long	baselen;

	baselen = ft_strlen(base);
	if (nbr >= baselen)
		ft_printnbr_u(nbr / baselen, base, count);
	ft_printchar(base[(nbr % baselen)], count);
}
