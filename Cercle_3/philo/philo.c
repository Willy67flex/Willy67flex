/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:40:46 by whollebe          #+#    #+#             */
/*   Updated: 2026/01/12 15:21:47 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_setting	data;

	if (check_input(argc, argv, &data) == 1)
		return (print_error_msg(), 1);
	if (init_data(&data) != 0)
		return (printf("Error: Malloc or Mutex failed\n"), 1);
	data.start_time = get_time();
	data.dead_flag = 0;
	init_philos(&data);
	if (create_threads(&data) != 0)
		return (printf("Error: Thread creation or join failed\n"),
			ft_exit(&data), 1);
	ft_exit(&data);
	return (0);
}
