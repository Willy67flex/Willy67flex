/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_perimeter_wall.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:28:19 by whollebe          #+#    #+#             */
/*   Updated: 2025/12/17 13:30:06 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*put_other_walls(t_game *game, int x, int y, int max_y)
{
	void	*img;

	img = put_special_wall(game, x, y, max_y);
	if (img)
		return (img);
	img = put_horizontal_wall(game, x, y);
	if (img)
		return (img);
	img = put_vertical_wall(game, x, y);
	if (img)
		return (img);
	img = put_corner_wall(game, x, y);
	if (img)
		return (img);
	img = put_intersection_wall(game, x, y);
	return (img);
}

void	put_perimeter_wall(t_game *game, int x, int y)
{
	void	*img;
	int		max_x;
	int		max_y;
	int		noise;
	int		v2;

	max_x = game->map_width - 1;
	max_y = game->map_height - 1;
	noise = (x * 7) + (y * 13);
	v2 = noise % 2;
	if (y == max_y && x == 0)
		img = game->texture.corner_d_l[2];
	else if (y == max_y && x == max_x)
		img = game->texture.corner_d_r[2];
	else if (y == max_y)
		img = game->texture.wall[v2];
	else
		img = put_other_walls(game, x, y, max_y - 1);
	put_img(game, img, x, y);
}
