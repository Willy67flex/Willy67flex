/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:34:43 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/11 13:35:09 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_chdir_error(t_data *data, char *str)
{
	int			err_code;

	err_code = errno;
	print_sys_error("cd", str, err_code);
	data->exit_code = 1;
}

void	ft_option_error(t_data *data, char option)
{
	data->exit_code = 1;
	ft_putstr_fd("Minishell: cd: -", 2);
	ft_putchar_fd(option, 2);
	ft_putstr_fd(": invalid option\n", 2);
	ft_putstr_fd("cd: usage: cd without options\n", 2);
}
