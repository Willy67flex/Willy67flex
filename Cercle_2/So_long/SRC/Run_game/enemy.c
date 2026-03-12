/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:58:49 by whollebe          #+#    #+#             */
/*   Updated: 2025/12/17 12:11:41 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	try_move(t_game *game, int i, int dx, int dy)
{
	int	dir;

	if (dx == 1)
		dir = DIR_RIGHT;
	else if (dx == -1)
		dir = DIR_LEFT;
	else if (dy == 1)
		dir = DIR_DOWN;
	else
		dir = DIR_UP;
	if (is_valid_enemy_move(game, game->x_enemy[i] + dx, game->y_enemy[i] + dy))
	{
		game->enemy_dir[i] = dir;
		update_single_enemy(game, i, game->x_enemy[i] + dx,
			game->y_enemy[i] + dy);
		return (1);
	}
	return (0);
}

void	solve_x_prio(t_game *game, int i, int dx, int dy)
{
	int	sx;
	int	sy;

	sx = get_sign(dx, 0);
	sy = get_sign(dy, 0);
	if (sx != 0 && try_move(game, i, sx, 0))
		return ;
	if (sy != 0 && try_move(game, i, 0, sy))
		return ;
	if (try_move(game, i, 0, 1))
		return ;
	if (try_move(game, i, 0, -1))
		return ;
}

void	solve_y_prio(t_game *game, int i, int dx, int dy)
{
	int	sx;
	int	sy;

	sx = get_sign(dx, 0);
	sy = get_sign(dy, 0);
	if (sy != 0 && try_move(game, i, 0, sy))
		return ;
	if (sx != 0 && try_move(game, i, sx, 0))
		return ;
	if (try_move(game, i, 1, 0))
		return ;
	if (try_move(game, i, -1, 0))
		return ;
}

void	move_single_enemy(t_game *game, int i)
{
	int	dx;
	int	dy;
	int	adx;
	int	ady;

	dx = game->x - game->x_enemy[i];
	dy = game->y - game->y_enemy[i];
	if (dx < 0)
		adx = -dx;
	else
		adx = dx;
	if (dy < 0)
		ady = -dy;
	else
		ady = dy;
	if (adx >= ady)
		solve_x_prio(game, i, dx, dy);
	else
		solve_y_prio(game, i, dx, dy);
}

void	enemy_move(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->nb_enemy)
	{
		move_single_enemy(game, i);
		i++;
	}
}
