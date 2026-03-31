/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 16:10:57 by ele-moig          #+#    #+#             */
/*   Updated: 2026/03/31 12:10:24 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_imgb	*get_wall_texture(t_game *game, t_ray *ray)
{
	if (game->map[ray->map_y][ray->map_x] == 'D')
		return (&game->texture->door);
	if (ray->side == 0)
	{
		if (ray->dir->x >= 0)
			return (&game->texture->west);
		return (&game->texture->east);
	}
	else
	{
		if (ray->dir->y >= 0)
			return (&game->texture->north);
		return (&game->texture->south);
	}
}

void	text_calc(t_game *game, t_ray *ray)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = game->pos->y + ray->perp_wall_dist * ray->dir->y;
	else
		wall_x = game->pos->x + ray->perp_wall_dist * ray->dir->x;
	wall_x -= floor((wall_x));
	ray->tex_x = (int)(wall_x * (double)TEXT_WIDTH);
	if (ray->side == 0 && ray->dir->x > 0)
		ray->tex_x = TEXT_WIDTH - ray->tex_x - 1;
	if (ray->side == 1 && ray->dir->y < 0)
		ray->tex_x = TEXT_WIDTH - ray->tex_x - 1;
	ray->step = 1.0 * TEXT_HEIGHT / ray->line_h;
	ray->text_pos = (ray->draw_start - WIN_HEIGHT / 2.0 + ray->line_h / 2.0)
		* ray->step;
}
