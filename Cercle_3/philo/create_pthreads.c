/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pthreads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:44:30 by whollebe          #+#    #+#             */
/*   Updated: 2026/01/08 11:17:53 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_setting *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
		if (pthread_create(&data->philos[i].thread, NULL, &philo_routine,
				&data->philos[i]))
			return (1);
	monitor(data);
	i = -1;
	while (++i < data->nb_philo)
		if (pthread_join(data->philos[i].thread, NULL))
			return (1);
	return (0);
}
