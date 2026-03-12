/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_items.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:00:39 by whollebe          #+#    #+#             */
/*   Updated: 2025/12/17 12:27:28 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_exit_door(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'E')
			{
				put_img(game, game->texture.grass[(x * 7 + y * 13) % 3], x, y);
				put_img(game, game->texture.exit[1], x, y);
			}
			x++;
		}
		y++;
	}
}

void	draw_exit_sprite(t_game *game, int x, int y, int is_open)
{
	void			*sprite;
	int				screen_x;
	int				screen_y;

	if (is_open)
		sprite = game->texture.exit[1];
	else
		sprite = game->texture.exit[0];
	screen_x = x * IMG_SIZE;
	screen_y = y * IMG_SIZE;
	completed_map(game, screen_x, screen_y, sprite);
}

void	draw_coin_sprite(t_game *game, int x, int y)
{
	void			*sprite;
	int				screen_x;
	int				screen_y;

	sprite = game->sprites.coin[game->sprites.frame_coin];
	screen_x = x * IMG_SIZE;
	screen_y = y * IMG_SIZE;
	completed_map(game, screen_x, screen_y, sprite);
}

void	update_coins(t_game *game)
{
	int	x;
	int	y;
	int	noise;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C')
			{
				noise = (x * 7) + (y * 13);
				put_img(game, game->texture.grass[noise % 3], x, y);
				draw_coin_sprite(game, x, y);
			}
			x++;
		}
		y++;
	}
}
