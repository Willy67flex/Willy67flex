/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:00:13 by whollebe          #+#    #+#             */
/*   Updated: 2025/12/17 13:50:44 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_game *game, int x, int y)
{
	int	noise;

	noise = (x * 7) + (y * 13);
	put_img(game, game->texture.grass[noise % 3], x, y);
	if (game->map[y][x] == '1')
		put_perimeter_wall(game, x, y);
	else if (game->map[y][x] == 'C')
		draw_coin_sprite(game, x, y);
	else if (game->map[y][x] == 'E')
	{
		if (game->collectibles == 0)
			draw_exit_sprite(game, x, y, 1);
		else
			draw_exit_sprite(game, x, y, 0);
	}
	else if (game->map[y][x] == 'P')
		put_player_on_map(game, x, y);
	else if (game->map[y][x] == 'M')
		put_ennemy_on_map(game, x, y, DIR_DOWN);
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map_height)
	{
		x = -1;
		while (++x < game->map_width)
			draw_map(game, x, y);
	}
	print_moovs(game);
	draw_ui(game);
}

void	put_player_on_map(t_game *game, int map_x, int map_y)
{
	int				screen_x;
	int				screen_y;
	void			*sprite;

	if (game->sprites.direction == DIR_UP)
		sprite = game->sprites.idle_up[game->sprites.current_frame];
	else if (game->sprites.direction == DIR_LEFT)
		sprite = game->sprites.idle_left[game->sprites.current_frame];
	else if (game->sprites.direction == DIR_RIGHT)
		sprite = game->sprites.idle_right[game->sprites.current_frame];
	else
		sprite = game->sprites.idle_down[game->sprites.current_frame];
	screen_x = map_x * IMG_SIZE;
	screen_y = map_y * IMG_SIZE;
	completed_map(game, screen_x, screen_y, sprite);
}

void	put_ennemy_on_map(t_game *game, int map_x, int map_y, int dir)
{
	int				screen_x;
	int				screen_y;
	void			*sprite;
	int				frame;

	frame = game->sprites.current_frame_enmy;
	if (dir == DIR_UP)
		sprite = game->sprites.enmy_up[frame];
	else if (dir == DIR_LEFT)
		sprite = game->sprites.enmy_left[frame];
	else if (dir == DIR_RIGHT)
		sprite = game->sprites.enmy_right[frame];
	else
		sprite = game->sprites.enmy_down[frame];
	screen_x = map_x * IMG_SIZE;
	screen_y = map_y * IMG_SIZE;
	completed_map(game, screen_x, screen_y, sprite);
}

void	update_player(t_game *game, int x, int y, int with_player)
{
	int	noise;

	noise = (x * 7) + (y * 13);
	put_img(game, game->texture.grass[noise % 3], x, y);
	if (game->map[y][x] == 'E')
	{
		if (game->collectibles == 0)
			draw_exit_sprite(game, x, y, 1);
		else
			draw_exit_sprite(game, x, y, 0);
	}
	if (with_player)
		put_player_on_map(game, x, y);
	print_moovs(game);
}
