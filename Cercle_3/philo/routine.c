/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:40:49 by whollebe          #+#    #+#             */
/*   Updated: 2026/01/08 11:29:33 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	write_status("has taken a fork (right)", philo);
	write_status("is eating", philo);
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal_time = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_lock);
	ft_usleep(philo, philo->setting->time_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	*philo_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (dead_loop(philo) != 1)
	{
		pthread_mutex_lock(philo->l_fork);
		write_status("has taken a fork (left)", philo);
		if (philo->setting->nb_philo == 1)
		{
			ft_usleep(philo, philo->setting->time_die);
			pthread_mutex_unlock(philo->l_fork);
			return (NULL);
		}
		eat_routine(philo);
		write_status("is sleeping", philo);
		ft_usleep(philo, philo->setting->time_sleep);
		write_status("is thinking", philo);
	}
	return (NULL);
}
