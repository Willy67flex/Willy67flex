/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:38:33 by whollebe          #+#    #+#             */
/*   Updated: 2026/01/08 10:40:27 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_exit(t_setting *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].meal_lock);
	}
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->dead_lock);
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}

long	ft_atol(const char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (result > 2147483647)
		return (-1);
	return (result);
}

void	print_error_msg(void)
{
	printf("Usage-> ./philo <number_of_philosopher> < time_to_die> <time_to_e");
	printf("at> <time_to_sleep> <number_of_times_each_philosopher_must_eat>\n");
	printf("\nWith : \n1 <= nb_philo <= 200,\ntime_to_die > 0 (ms, max = 2147");
	printf("483647 ~= 25 days),\ntime_to_eat > 0 (ms, max = 2147483647 ~= 25" );
	printf("days),\ntime_to_sleep > 0 (ms, max = 2147483647 ~= 25 days),");
	printf("\n(option)number_of_times_each_philosopher_must_eat >= 0.\n");
}
