/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:48:43 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/31 14:12:34 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_game *game, double move_x, double move_y)
{
	double	new_x;
	double	new_y;

	new_x = game->pos->x + move_x;
	new_y = game->pos->y + move_y;
	if (game->map[(int)game->pos->y][(int)new_x] != '1' &&
		game->map[(int)game->pos->y][(int)new_x] != 'D')
		game->pos->x = new_x;
	if (game->map[(int)new_y][(int)game->pos->x] != '1' &&
		game->map[(int)new_y][(int)game->pos->x] != 'D')
		game->pos->y = new_y;
}

void	move_forward(t_game *game)
{
	double	speed;

	if (game->key_shift)
		speed = SPRINT_SPEED;
	else
		speed = MOVE_SPEED;
	move_player(game, game->dir->x * speed * game->dt,
		game->dir->y * speed * game->dt);
}

void	move_backward(t_game *game)
{
	double	speed;

	if (game->key_shift)
		speed = SPRINT_SPEED;
	else
		speed = MOVE_SPEED;
	move_player(game, -(game->dir->x * speed * game->dt),
		-(game->dir->y * speed * game->dt));
}

void	strafe_left(t_game *game)
{
	double	speed;

	if (game->key_shift)
		speed = SPRINT_SPEED;
	else
		speed = MOVE_SPEED;
	move_player(game, -(game->plane->x * speed * game->dt),
		-(game->plane->y * speed * game->dt));
}

void	strafe_right(t_game *game)
{
	double	speed;

	if (game->key_shift)
		speed = SPRINT_SPEED;
	else
		speed = MOVE_SPEED;
	move_player(game, game->plane->x * speed * game->dt,
		game->plane->y * speed * game->dt);
}
