/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:04:39 by ele-moig          #+#    #+#             */
/*   Updated: 2026/03/27 11:14:47 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int key_handler(int keycode, t_game *game)
{
	double speed = 0.15;

	if (keycode == KEY_ESC)
		close_window(game);
	else if (keycode == KEY_W)
		move_player(game, game->dir->x * speed, game->dir->y * speed);
	else if (keycode == KEY_S)
		move_player(game, -game->dir->x * speed, -game->dir->y * speed);
	else if (keycode == KEY_A)
		move_player(game, -game->plane->x * speed, -game->plane->y * speed);
	else if (keycode == KEY_D)
		move_player(game, game->plane->x * speed, game->plane->y * speed);
	return (0);
}
