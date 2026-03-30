/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 11:30:25 by ele-moig          #+#    #+#             */
/*   Updated: 2026/03/27 11:30:34 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	init_game(&game);
	check_input(argv[1], &game, argc);
	printf("\nParametre de la map:\n\n");
	printf("%s\n", game.map_content->n_txtr);
	printf("%s\n", game.map_content->s_txtr);
	printf("%s\n", game.map_content->w_txtr);
	printf("%s\n", game.map_content->e_txtr);
	printf("%d\n", game.texture->hex_floor);
	printf("%d\n", game.texture->hex_ceiling);
	int	i = -1;
	while (game.map[++i])
		printf("%s\n", game.map[i]);
	printf("\npos x: %f\n", game.pos->x);
	printf("pos y: %f\n", game.pos->y);
	printf("\nVecteur dir: (%f, %f)\n", game.dir->x, game.dir->y);
	printf("Vecteur plane: (%f, %f)\n", game.plane->x, game.plane->y);
	run_game(&game);
	return (0);
}
