/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 12:02:40 by ele-moig          #+#    #+#             */
/*   Updated: 2026/03/31 12:09:46 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall_line(t_game *game, int x, t_ray *ray)
{
	t_imgb	*tex;
	int		*screen_buf;
	int		*tex_buf;
	int		color;

	ft_draw_wall_calc(game, ray);
	tex = get_wall_texture(game, ray);
	text_calc(game, ray);
	screen_buf = (int *)game->addr;
	tex_buf = (int *)tex->addr;
	ft_text_calc_init(game, tex, ray, x);
	while (ray->draw_start <= ray->draw_end)
	{
		ray_tex_check(game, ray, tex);
		color = tex_buf[(ray->tex_y * tex->tex_pitch) + ray->tex_x];
		if (ray->side == 1)
			color = (color >> 1) & 8355711;
		screen_buf[tex->index] = color;
		tex->index += tex->screen_pitch;
		ray->draw_start++;
	}
}

void	raycasting(t_game *game)
{
	int		x;
	t_ray	*ray;

	ray = game->ray;
	x = 0;
	while (x < game->win_width)
	{
		ft_ray_calc(game, ray, x);
		ft_ray_dir_check(game, ray);
		ray->hit = 0;
		perform_dda(game, ray);
		draw_wall_line(game, x, ray);
		x++;
	}
}

void	draw_floor_and_ceiling(t_game *game)
{
	int	*buffer;
	int	total_pixels;
	int	px_nb_length;
	int	i;

	buffer = (int *)game->addr;
	px_nb_length = game->line_length / 4;
	total_pixels = px_nb_length * game->win_height;
	i = 0;
	while (i < total_pixels / 2)
	{
		buffer[i] = game->texture->hex_ceiling;
		i++;
	}
	while (i < total_pixels)
	{
		buffer[i] = game->texture->hex_floor;
		i++;
	}
}

void	ray_tex_check(t_game *game, t_ray *ray, t_imgb *tex)
{
	int	d;

	d = ray->draw_start * 256 - game->win_height * 128 + ray->line_h * 128;
	ray->tex_y = ((d * tex->height) / ray->line_h) / 256;
	if (ray->tex_y < 0)
		ray->tex_y = 0;
	if (ray->tex_y >= tex->height)
		ray->tex_y = tex->height - 1;
}
