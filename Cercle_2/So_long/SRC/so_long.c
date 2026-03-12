/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:00:05 by whollebe          #+#    #+#             */
/*   Updated: 2025/12/15 17:38:42 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <math.h>

int	main(int argc, char **argv)
{
	t_game	game;
	t_char	character;

	ft_bzero(&game, sizeof(t_game));
	check_input(argc, argv);
	check_map(argv[1], &game, &character);
	run_game(&game);
	return (0);
}
