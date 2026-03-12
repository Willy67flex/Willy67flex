/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pthread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:41:52 by whollebe          #+#    #+#             */
/*   Updated: 2026/01/08 11:18:28 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(&philo->setting->dead_lock);
	if (philo->setting->dead_flag == 1)
		return (pthread_mutex_unlock(&philo->setting->dead_lock), 1);
	pthread_mutex_unlock(&philo->setting->dead_lock);
	return (0);
}

void	print_dead(t_setting *data, int id)
{
	pthread_mutex_lock(&data->write_lock);
	printf("%ld %d died\n", get_time() - data->start_time, id);
	pthread_mutex_unlock(&data->write_lock);
	pthread_mutex_lock(&data->dead_lock);
	data->dead_flag = 1;
	pthread_mutex_unlock(&data->dead_lock);
}

void	ft_usleep(t_philo *philo, long time)
{
	long	current_time;
	long	end;

	end = get_time() + time;
	current_time = get_time();
	while (current_time < end)
	{
		if (dead_loop(philo))
			return ;
		usleep(500);
		current_time = get_time();
	}
}

void	write_status(char *str, t_philo *philo)
{
	long	time;

	pthread_mutex_lock(&philo->setting->write_lock);
	if (dead_loop(philo))
	{
		pthread_mutex_unlock(&philo->setting->write_lock);
		return ;
	}
	time = get_time() - philo->setting->start_time;
	printf("%ld %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->setting->write_lock);
}
