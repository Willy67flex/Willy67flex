/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:45:12 by whollebe          #+#    #+#             */
/*   Updated: 2025/12/17 13:48:05 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verif_enemy(t_char *character)
{
	if (character->m == 0)
		return ;
	else if (character->o < 50 && character->m < 1)
		msg_error("map to smal for 2 and more enemies");
	else if (character->o < 100 && character->m > 2)
		msg_error("map to smal for 3 and more enemies");
	else if (character->o < 150 && character->m > 3)
		msg_error("map to smal for 4 and more enemies");
	else if (character->o < 200 && character->m > 4)
		msg_error("map to smal for 5 and more enemies");
	else if (character->o < 250 && character->m > 5)
		msg_error("map to smal for 6 and more enemies");
	else if (character->o < 300 && character->m > 6)
		msg_error("map to smal for 7 and more enemies");
	else if (character->o < 350 && character->m > 7)
		msg_error("map to smal for 8 and more enemies");
	else if (character->o < 400 && character->m > 8)
		msg_error("map to smal for 9 and more enemies");
	else if (character->o < 450 && character->m > 9)
		msg_error("map to smal for 10 and more enemies");
	else if (character->m > 10)
		msg_error("The map cannot contain more than 10 enemies");
}

void	malloc_enemy(t_game *game, t_char *character)
{
	game->nb_enemy = character->m;
	game->x_enemy = malloc(sizeof(int) * game->nb_enemy);
	game->y_enemy = malloc(sizeof(int) * game->nb_enemy);
	game->start_x_enemy = malloc(sizeof(int) * game->nb_enemy);
	game->start_y_enemy = malloc(sizeof(int) * game->nb_enemy);
	game->enemy_dir = malloc(sizeof(int) * game->nb_enemy);
	if (!game->x_enemy || !game->y_enemy || !game->start_x_enemy
		|| !game->start_y_enemy || !game->enemy_dir)
		msg_error("Malloc failed for enemies");
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	init_ennemy_pos(t_game *game, int x, int y, int *counter)
{
	game->y_enemy[*counter] = y;
	game->x_enemy[*counter] = x;
	game->start_y_enemy[*counter] = y;
	game->start_x_enemy[*counter] = x;
	game->enemy_dir[*counter] = DIR_DOWN;
	(*counter)++;
}

void	get_enemies_pos(t_game *game, t_char *character)
{
	int	y;
	int	x;
	int	counter;
	int	dist;

	y = -1;
	counter = 0;
	malloc_enemy(game, character);
	while (++y < game->map_height)
	{
		x = -1;
		while (++x < game->map_width)
		{
			if (game->map[y][x] == 'M')
			{
				dist = ft_abs(x - game->start_x) + ft_abs(y - game->start_y);
				if (dist < 5)
					msg_error("M spawning too close to the P (< 5 blocks)");
				init_ennemy_pos(game, x, y, &counter);
			}
		}
	}
}
