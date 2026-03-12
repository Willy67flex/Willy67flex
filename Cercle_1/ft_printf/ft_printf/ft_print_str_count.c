/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:19:16 by whollebe          #+#    #+#             */
/*   Updated: 2025/10/21 17:05:55 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str_count(char *str, int *count_print)
{
	int	i;

	i = 0;
	if (!str)
	{
		str = "(null)";
		while (str[i])
		{
			ft_write_count(str[i], count_print);
			i++;
		}
	}
	while (str[i])
	{
		ft_write_count(str[i], count_print);
		i++;
	}
}
