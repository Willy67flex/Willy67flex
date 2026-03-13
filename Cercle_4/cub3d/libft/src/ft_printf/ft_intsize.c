/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:36:30 by ele-moig          #+#    #+#             */
/*   Updated: 2025/10/13 16:25:31 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intsize(int nbr)
{
	int			intsize;
	long int	nb;

	intsize = 1;
	nb = nbr;
	if (nb < 0)
	{
		nb = -nb;
		intsize++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		intsize++;
	}
	return (intsize);
}
