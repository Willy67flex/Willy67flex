/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:02:49 by ele-moig          #+#    #+#             */
/*   Updated: 2025/10/14 12:37:19 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printuint(uintptr_t nbr, char *base, int *count)
{
	if (nbr >= 16)
		ft_printuint(nbr / 16, base, count);
	ft_printchar(base[(nbr % 16)], count);
}

void	ft_print_ptr(void *ptr, int *count)
{
	if (!ptr)
	{
		ft_printstr("(nil)", count);
		return ;
	}
	ft_printstr("0x", count);
	ft_printuint((uintptr_t)ptr, LOW_HEX_BASE, count);
}
