/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_hexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:18:47 by ele-moig          #+#    #+#             */
/*   Updated: 2025/10/14 12:31:06 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printnbr_hexa(unsigned int nbr, char *base, int *count)
{
	if (nbr >= 16)
		ft_printnbr_hexa(nbr / 16, base, count);
	ft_printchar(base[(nbr % 16)], count);
}
