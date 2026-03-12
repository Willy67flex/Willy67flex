/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:19:11 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/11 13:58:05 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	count_args_node(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atol(char *str, long *result)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (ft_isdigit(str[i]))
	{
		if (res > LONG_MAX / 10 || (res == LONG_MAX / 10
				&& str[i] - '0' > 7 + (1 - sign) / 2))
			return (0);
		res = (res * 10) + (str[i++] - '0');
	}
	*result = res * sign;
	return (1);
}

int	ft_exit(t_data *data, t_cmd_node *runner, int flag)
{
	long	code;

	if (flag == 1)
		printf("exit\n");
	if (runner->args[1] == NULL)
	{
		code = data->final_exit_code;
		free_all(data, 1);
		exit((int)code);
	}
	if (ft_is_number(runner->args[1]) == 0
		|| ft_atol(runner->args[1], &code) == 0)
	{
		print_custom_error("exit", runner->args[1],
			"numeric argument required");
		free_all(data, 1);
		exit(2);
	}
	if (runner->args[2] != NULL)
		return (print_custom_error("exit", NULL, "too many arguments"),
			data->exit_code = 1, 1);
	free_all(data, 1);
	exit((int)code);
}
