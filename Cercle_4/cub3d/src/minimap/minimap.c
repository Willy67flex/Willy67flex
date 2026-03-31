/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 10:48:38 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/31 14:50:52 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_block_size(t_game *game)
{
	int	block_size;
	int	max_block_w;
	int	max_block_h;

	max_block_w = (game->win_width / 3) / game->map_width;
	max_block_h = (game->win_height / 3) / game->map_height;
	block_size = max_block_w;
	if (max_block_h < block_size)
		block_size = max_block_h;
	if (block_size < 3)
		block_size = 3;
	if (block_size > 15)
		block_size = 15;
	return (block_size);
}

void	draw_mm_player(t_game *game, int block_size)
{
	int	i;
	int	j;
	int	p_size;

	p_size = block_size / 2;
	if (p_size < 2)
		p_size = 2;
	i = -p_size;
	while (i < p_size)
	{
		j = -p_size;
		while (j < p_size)
		{
			my_mlx_pixel_put(game, 15 + (game->pos->x * block_size) + i, 15
				+ (game->pos->y * block_size) + j, get_rgb(255, 0, 0));
			j++;
		}
		i++;
	}
}

void	draw_mm_square(t_game *game, int x, int y, int block_size)
{
	int	i;
	int	j;
	int	color;

	if (game->map[y][x] == '1')
		color = get_rgb(255, 255, 255);
	else if (game->map[y][x] == 'D' || game->map[y][x] == 'O')
		color = get_rgb(91, 60, 17);
	else
		color = get_rgb(100, 100, 100);
	i = -1;
	while (++i < block_size)
	{
		j = 0;
		while (j < block_size)
		{
			my_mlx_pixel_put(game, 15 + (x * block_size) + i, 15
				+ (y * block_size) + j, color);
			j++;
		}
	}
}

void	set_map_width(t_game *game)
{
	int	x;
	int	y;

	if (game->map_width == 0)
	{
		y = -1;
		while (game->map[++y])
		{
			x = ft_strlen(game->map[y]);
			if (x > game->map_width)
				game->map_width = x;
		}
	}
}

void	draw_minimap(t_game *game)
{
	int	x;
	int	y;
	int	block_size;

	set_map_width(game);
	block_size = get_block_size(game);
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '1' || game->map[y][x] == '0'
				|| game->map[y][x] == 'N' || game->map[y][x] == 'S'
				|| game->map[y][x] == 'E' || game->map[y][x] == 'W'
				|| game->map[y][x] == 'D' || game->map[y][x] == 'O')
				draw_mm_square(game, x, y, block_size);
		}
	}
	draw_mm_player(game, block_size);
}
