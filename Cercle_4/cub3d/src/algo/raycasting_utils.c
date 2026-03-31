/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:44:06 by ele-moig          #+#    #+#             */
/*   Updated: 2026/03/31 12:12:23 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_ray_dir_check(t_game *game, t_ray *ray)
{
	if (ray->dir->x < 0)
	{
		ray->step_x = -1;
		ray->side_dist->x = (game->pos->x - ray->map_x) * ray->delta_dist->x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist->x = (ray->map_x + 1.0 - game->pos->x)
			* ray->delta_dist->x;
	}
	if (ray->dir->y < 0)
	{
		ray->step_y = -1;
		ray->side_dist->y = (game->pos->y - ray->map_y) * ray->delta_dist->y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist->y = (ray->map_y + 1.0 - game->pos->y)
			* ray->delta_dist->y;
	}
}

void	ft_ray_calc(t_game *game, t_ray *ray, int x)
{
	double	camera_x;

	camera_x = (2.0 * x) / (double)game->win_width - 1.0;
	ray->dir->x = game->dir->x + game->plane->x * camera_x;
	ray->dir->y = game->dir->y + game->plane->y * camera_x;
	ray->map_x = (int)game->pos->x;
	ray->map_y = (int)game->pos->y;
	if (ray->dir->x == 0)
		ray->delta_dist->x = 1e30;
	else
		ray->delta_dist->x = fabs(1.0 / ray->dir->x);
	if (ray->dir->y == 0)
		ray->delta_dist->y = 1e30;
	else
		ray->delta_dist->y = fabs(1.0 / ray->dir->y);
}

void	perform_dda(t_game *game, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist->x < ray->side_dist->y)
		{
			ray->side_dist->x += ray->delta_dist->x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist->y += ray->delta_dist->y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
		else if (game->map[ray->map_y][ray->map_x] == 'D')
			ray->hit = 2;
	}
}

void	ft_draw_wall_calc(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist->x - ray->delta_dist->x;
	else
		ray->perp_wall_dist = ray->side_dist->y - ray->delta_dist->y;
	if (ray->perp_wall_dist < 0.0001)
		ray->perp_wall_dist = 0.0001;
	ray->line_h = (int)(game->win_height / ray->perp_wall_dist);
	ray->draw_start = -ray->line_h / 2 + game->win_height / 2;
	ray->draw_end = ray->line_h / 2 + game->win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= game->win_height)
		ray->draw_end = game->win_height - 1;
}

void	ft_text_calc_init(t_game *game, t_imgb *tex, t_ray *ray, int x)
{
	tex->screen_pitch = game->line_length / 4;
	tex->tex_pitch = tex->line_length / 4;
	tex->index = (ray->draw_start * tex->screen_pitch) + x;
}
