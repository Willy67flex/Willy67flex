/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 10:48:38 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/30 13:24:37 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_mm_player(t_game *game)
{
	int i;
	int j;
	int p_size;

	p_size = 4;
	i = -p_size;
	while (i < p_size)
	{
		j = -p_size;
		while (j < p_size)
		{
			my_mlx_pixel_put(game, 15 + (game->pos->x * 8) + i, 15 + (game->pos->y * 8) + j, get_rgb(255, 0, 0));
			j++;
		}
		i++;
	}
}

void	draw_mm_square(t_game *game, int x, int y, int color)
{
	int i;
	int j;

	i = -1;
	while (++i < 8)
	{
		j = 0;
		while (j < 8)
		{
			my_mlx_pixel_put(game, 15 + (x * 8) + i, 15 + (y * 8) + j, color);
			j++;
		}
	}
}

void	draw_minimap(t_game *game)
{
	int x;
	int y;

	y = -1;
	while (game->map[++y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				draw_mm_square(game, x, y, get_rgb(255, 255, 255));
			else if (game->map[y][x] == '0')
				draw_mm_square(game, x, y, get_rgb(100, 100, 100));
			else if (game->map[y][x] == 'D')
				draw_mm_square(game, x, y, get_rgb(91, 60, 17));
			x++;
		}
	}
	draw_mm_player(game);
}
