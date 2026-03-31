/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 11:30:25 by ele-moig          #+#    #+#             */
/*   Updated: 2026/03/31 10:58:23 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_game(&game);
	check_input(argv[1], &game, argc);
	run_game(&game);
	return (0);
}
