/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr_fd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:08:34 by whollebe          #+#    #+#             */
/*   Updated: 2025/11/17 13:37:30 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_unsigned_nbr_fd(unsigned int n, int fd)
{
	if (n >= 10)
		ft_put_unsigned_nbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}
