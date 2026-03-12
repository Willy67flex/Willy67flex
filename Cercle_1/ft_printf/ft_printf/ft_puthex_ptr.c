/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:06:39 by whollebe          #+#    #+#             */
/*   Updated: 2025/10/14 13:10:38 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_ptr(uintptr_t n, int *count_print)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		ft_puthex_ptr(n / 16, count_print);
	ft_write_count(base[n % 16], count_print);
}
