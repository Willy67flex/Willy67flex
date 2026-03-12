/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:47:43 by ele-moig          #+#    #+#             */
/*   Updated: 2026/03/11 14:40:16 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_sys_error(char *cmd, char *middle, int err_code)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	if (middle != NULL)
	{
		ft_putstr_fd(middle, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(strerror(err_code), 2);
	ft_putstr_fd("\n", 2);
}

void	print_custom_error(char *cmd, char *middle, char *custom)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	if (middle != NULL)
	{
		ft_putstr_fd(middle, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(custom, 2);
	ft_putstr_fd("\n", 2);
}
