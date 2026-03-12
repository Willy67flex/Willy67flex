/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:39:32 by whollebe          #+#    #+#             */
/*   Updated: 2026/01/08 10:40:06 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_setting *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
		return (1);
	data->philos = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philos)
		return (free(data->forks), 1);
	if (pthread_mutex_init(&data->write_lock, NULL) != 0)
		return (free(data->forks), free(data->philos), 1);
	if (pthread_mutex_init(&data->dead_lock, NULL) != 0)
		return (pthread_mutex_destroy(&data->write_lock), free(data->forks),
			free(data->philos), 1);
	i = -1;
	while (++i < data->nb_philo)
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (ft_exit(data), 1);
	return (0);
}

void	init_philos(t_setting *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal_time = data->start_time;
		data->philos[i].setting = data;
		pthread_mutex_init(&data->philos[i].meal_lock, NULL);
		data->philos[i].l_fork = &data->forks[i];
		data->philos[i].r_fork = &data->forks[(i + 1) % data->nb_philo];
	}
}
