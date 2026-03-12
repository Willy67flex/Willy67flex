/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:34:50 by whollebe          #+#    #+#             */
/*   Updated: 2025/12/17 11:35:08 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	destroy_all_images(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game->map, game->map_height);
	if (game->x_enemy)
		free(game->x_enemy);
	if (game->y_enemy)
		free(game->y_enemy);
	if (game->start_x_enemy)
		free(game->start_x_enemy);
	if (game->start_y_enemy)
		free(game->start_y_enemy);
	if (game->enemy_dir)
		free(game->enemy_dir);
	exit(0);
	return (0);
}

int	key_handler(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	else if (game->game_over == 1)
		return (0);
	else if (keycode == KEY_W || keycode == KEY_UP)
	{
		game->sprites.direction = DIR_UP;
		player_move(game, game->y - 1, game->x);
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		game->sprites.direction = DIR_DOWN;
		player_move(game, game->y + 1, game->x);
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		game->sprites.direction = DIR_LEFT;
		player_move(game, game->y, game->x - 1);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->sprites.direction = DIR_RIGHT;
		player_move(game, game->y, game->x + 1);
	}
	return (0);
}

void	init_window(t_game *game)
{
	int	w_px;
	int	h_px;

	game->mlx = mlx_init();
	if (!game->mlx)
		msg_error("MLX Init Failed");
	w_px = game->map_width * IMG_SIZE;
	h_px = game->map_height * IMG_SIZE;
	game->win = mlx_new_window(game->mlx, w_px, h_px, "so_long");
	if (!game->win)
	{
		free(game->mlx);
		msg_error("Window Creation Failed");
	}
	game->game_over = 0;
	mlx_hook(game->win, 2, 1L << 0, key_handler, game);
	mlx_hook(game->win, 17, 1L << 17, close_window, game);
}
