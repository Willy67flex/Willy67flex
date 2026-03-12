/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:37:02 by whollebe          #+#    #+#             */
/*   Updated: 2026/01/08 10:39:01 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_setting(int argc, char **argv, t_setting *data)
{
	data->nb_philo = ft_atol(argv[1]);
	data->time_die = ft_atol(argv[2]);
	data->time_eat = ft_atol(argv[3]);
	data->time_sleep = ft_atol(argv[4]);
	if (argc == 6)
		data->nb_meals = ft_atol(argv[5]);
	else
		data->nb_meals = -1;
	if (data->nb_philo < 1 || data->nb_philo > 200)
		return (1);
	if (data->time_die < 1 || data->time_eat < 1 || data->time_sleep < 1)
		return (1);
	if (argc == 6 && data->nb_meals < 0)
		return (1);
	return (0);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+')
		i++;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_input(int argc, char **argv, t_setting *data)
{
	int	i;

	i = 0;
	if (argc != 5 && argc != 6)
		return (1);
	while (++i < argc)
		if (is_valid_number(argv[i]))
			return (1);
	if (init_setting(argc, argv, data))
		return (1);
	return (0);
}
