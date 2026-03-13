/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:52:40 by ele-moig          #+#    #+#             */
/*   Updated: 2025/10/30 15:17:52 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_handle_type(char flag, va_list args, int *count)
{
	if (flag == 'c')
		ft_printchar(va_arg(args, int), count);
	else if (flag == 's')
		ft_printstr(va_arg(args, char *), count);
	else if (flag == 'd' || flag == 'i')
		ft_printnbr_base(va_arg(args, int), "0123456789", count);
	else if (flag == 'p')
		ft_print_ptr(va_arg(args, void *), count);
	else if (flag == 'x')
		ft_printnbr_hexa(va_arg(args, uintptr_t), LOW_HEX_BASE, count);
	else if (flag == 'X')
		ft_printnbr_hexa(va_arg(args, uintptr_t), UPP_HEX_BASE, count);
	else if (flag == '%')
		ft_printchar('%', count);
	else if (flag == 'u')
		ft_printnbr_u(va_arg(args, uintptr_t), "0123456789", count);
}
