/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:48:43 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/27 11:24:02 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	move_player(t_game *game, double move_x, double move_y)
{
	int		map_x;
	int		map_y;
	double	new_x;
	double	new_y;

	new_x = game->pos->x + move_x;
	new_y = game->pos->y + move_y;
	map_x = (int)new_x;
	map_y = (int)(game->pos->y);
	if (game->map[map_y][map_x] != '1')
		game->pos->x = new_x;
	map_x = (int)(game->pos->x);
	map_y = (int)new_y;
	if (game->map[map_y][map_x] != '1')
		game->pos->y = new_y;
}

void	strafe_left(t_game *game)
{
	double	move_speed;
	double	move_x;
	double	move_y;

	if (game->key_shift)
		move_speed = 0.30;
	else
		move_speed = 0.12;
	move_x = -(game->plane->x) * move_speed;
	move_y = -(game->plane->y) * move_speed;
	move_player(game, move_x, move_y);
}

void	move_forward(t_game *game)
{
	double	move_speed;
	double	move_x;
	double	move_y;

	if (game->key_shift)
		move_speed = 0.30;
	else
		move_speed = 0.12;
	move_x = game->dir->x * move_speed;
	move_y = game->dir->y * move_speed;
	move_player(game, move_x, move_y);
}

void	move_backward(t_game *game)
{
	double	move_speed;
	double	move_x;
	double	move_y;

	if (game->key_shift)
		move_speed = 0.30;
	else
		move_speed = 0.12;
	move_x = -(game->dir->x * move_speed);
	move_y = -(game->dir->y * move_speed);
	move_player(game, move_x, move_y);
}

void	strafe_right(t_game *game)
{
	double	move_speed;
	double	move_x;
	double	move_y;

	if (game->key_shift)
		move_speed = 0.30;
	else
		move_speed = 0.12;
	move_x = game->plane->x * move_speed;
	move_y = game->plane->y * move_speed;
	move_player(game, move_x, move_y);
}
