/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_fct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:01:38 by ele-moig          #+#    #+#             */
/*   Updated: 2026/04/08 13:05:04 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_move(int x, int y, t_game *game)
{
	int		center_x;
	int		center_y;
	double	delta_x;
	double	angle;

	(void)y;
	center_x = game->win_width / 2;
	center_y = game->win_height / 2;
	delta_x = (double)(x - center_x);
	if (delta_x != 0)
	{
		angle = (delta_x / game->win_width) * MOUSE_SENS;
		rotation_matrice(game, angle);
		mlx_mouse_move(game->mlx, game->win, center_x, center_y);
	}
	return (0);
}

void	run_game(t_game	*game)
{
	game->win_height = 1080;
	game->win_width = 1920;
	game->win = mlx_new_window(game->mlx,
			game->win_width, game->win_height, "Cub3D");
	game->img = mlx_new_image(game->mlx, game->win_width, game->win_height);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
			&game->line_length, &game->endian);
	mlx_mouse_hide(game->mlx, game->win);
	mlx_loop_hook(game->mlx, render_frame, game);
	mlx_hook(game->win, 6, (1L << 6), mouse_move, game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 1L << 17, close_window, game);
	mlx_loop(game->mlx);
}

int	render_frame(t_game *game)
{
	long long	current_time;

	current_time = get_time();
	if (game->old_time == 0)
		game->old_time = current_time;
	game->dt = (current_time - game->old_time) / 1000.0;
	game->old_time = current_time;
	if (game->dt > 0.1)
		game->dt = 0.1;
	move_handler(game);
	if (game->key_left)
		rotation_matrice(game, -ROT_SPEED * game->dt);
	if (game->key_right)
		rotation_matrice(game, ROT_SPEED * game->dt);
	draw_floor_and_ceiling(game);
	raycasting(game);
	draw_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

int	close_window(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	free_all(game, NULL);
	exit(0);
	return (0);
}
