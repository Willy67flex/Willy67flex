/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:49:26 by ele-moig          #+#    #+#             */
/*   Updated: 2026/03/31 14:01:00 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_handler(t_game *game)
{
	if (game->key_w)
		move_forward(game);
	if (game->key_s)
		move_backward(game);
	if (game->key_a)
		strafe_left(game);
	if (game->key_d)
		strafe_right(game);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	if (keycode == KEY_W)
		game->key_w = 1;
	if (keycode == KEY_S)
		game->key_s = 1;
	if (keycode == KEY_A)
		game->key_a = 1;
	if (keycode == KEY_D)
		game->key_d = 1;
	if (keycode == KEY_SHIFT)
		game->key_shift = 1;
	if (keycode == KEY_LEFT)
		game->key_left = 1;
	if (keycode == KEY_RIGHT)
		game->key_right = 1;
	if (keycode == KEY_E)
		open_door(game);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->key_w = 0;
	if (keycode == KEY_S)
		game->key_s = 0;
	if (keycode == KEY_A)
		game->key_a = 0;
	if (keycode == KEY_D)
		game->key_d = 0;
	if (keycode == KEY_SHIFT)
		game->key_shift = 0;
	if (keycode == KEY_LEFT)
		game->key_left = 0;
	if (keycode == KEY_RIGHT)
		game->key_right = 0;
	return (0);
}

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < game->win_width && y >= 0 && y < game->win_height)
	{
		dst = game->addr + (y * game->line_length + x
				* (game->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
