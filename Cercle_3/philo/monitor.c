/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:43:39 by whollebe          #+#    #+#             */
/*   Updated: 2026/01/08 10:44:05 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_all_ate(t_setting *data)
{
	int	i;
	int	finished_eating;

	if (data->nb_meals == -1)
		return (0);
	i = -1;
	finished_eating = 0;
	while (++i < data->nb_philo)
	{
		pthread_mutex_lock(&data->philos[i].meal_lock);
		if (data->philos[i].meals_eaten >= data->nb_meals)
			finished_eating++;
		pthread_mutex_unlock(&data->philos[i].meal_lock);
	}
	if (finished_eating == data->nb_philo)
		return (pthread_mutex_lock(&data->dead_lock), data->dead_flag = 1,
			pthread_mutex_unlock(&data->dead_lock), 1);
	return (0);
}

void	monitor(t_setting *data)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < data->nb_philo)
		{
			pthread_mutex_lock(&data->philos[i].meal_lock);
			if (get_time() - data->philos[i].last_meal_time >= data->time_die)
			{
				pthread_mutex_unlock(&data->philos[i].meal_lock);
				print_dead(data, data->philos[i].id);
				return ;
			}
			pthread_mutex_unlock(&data->philos[i].meal_lock);
		}
		if (check_if_all_ate(data))
			return ;
		usleep(1000);
	}
}
