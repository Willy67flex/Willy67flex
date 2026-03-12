/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:10:48 by whollebe          #+#    #+#             */
/*   Updated: 2026/01/08 11:19:06 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_setting	t_setting;
typedef struct s_philo		t_philo;

struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	meal_lock;
	t_setting		*setting;
};

struct s_setting
{
	long			nb_philo;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	long			nb_meals;
	long			start_time;
	int				dead_flag;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	t_philo			*philos;
};

int		check_input(int argc, char **argv, t_setting *data);
void	print_error_msg(void);
long	ft_atol(const char *str);
void	ft_exit(t_setting *data);
long	get_time(void);
int		dead_loop(t_philo *philo);
void	print_dead(t_setting *data, int id);
void	ft_usleep(t_philo *philo, long time);
void	write_status(char *str, t_philo *philo);
void	*philo_routine(void *ptr);
void	init_philos(t_setting *data);
int		init_data(t_setting *data);
int		create_threads(t_setting *data);
void	monitor(t_setting *data);

#endif // PHILO_H