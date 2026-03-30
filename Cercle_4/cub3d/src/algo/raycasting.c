
#include "cub3d.h"

void draw_wall_line(t_game *game, int x, t_ray *ray)
{
	t_imgb	*tex;
	int		*screen_buf;
	int		*tex_buf;
	int		screen_pitch;
	int		tex_pitch;
	int		index;
	int		color;

	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist->x - ray->delta_dist->x;
	else
		ray->perp_wall_dist = ray->side_dist->y - ray->delta_dist->y;
	if (ray->perp_wall_dist < 0.0001)
		ray->perp_wall_dist = 0.0001;
	ray->line_height = (int)(game->win_height / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + game->win_height / 2;
	ray->draw_end = ray->line_height / 2 + game->win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= game->win_height)
		ray->draw_end = game->win_height - 1;
	tex = get_wall_texture(game, ray);
	text_calc(game, ray);
	screen_buf = (int *)game->addr;
	tex_buf = (int *)tex->addr;
	screen_pitch = game->line_length / 4;
	tex_pitch = tex->line_length / 4;
	index = (ray->draw_start * screen_pitch) + x;
	while (ray->draw_start <= ray->draw_end)
	{
		int d = ray->draw_start * 256 - game->win_height * 128 + ray->line_height * 128;
		ray->tex_y = ((d * tex->height) / ray->line_height) / 256;
		if (ray->tex_y < 0) ray->tex_y = 0;
		if (ray->tex_y >= tex->height) ray->tex_y = tex->height - 1;
		color = tex_buf[(ray->tex_y * tex_pitch) + ray->tex_x];
		if (ray->side == 1)
			color = (color >> 1) & 8355711;
		screen_buf[index] = color;
		index += screen_pitch;
		ray->draw_start++;
	}
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
	}
}

void	raycasting(t_game *game)
{
	int		x;
	double	camera_x;
	t_ray	*ray;

	ray = game->ray;
	x = 0;
	while (x < game->win_width)
	{
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
		if (ray->dir->x < 0)
		{
			ray->step_x = -1;
			ray->side_dist->x = (game->pos->x - ray->map_x) * ray->delta_dist->x;
		}
		else
		{
			ray->step_x = 1;
			ray->side_dist->x = (ray->map_x + 1.0 - game->pos->x) * ray->delta_dist->x;
		}
		if (ray->dir->y < 0)
		{
			ray->step_y = -1;
			ray->side_dist->y = (game->pos->y - ray->map_y) * ray->delta_dist->y;
		}
		else
		{
			ray->step_y = 1;
			ray->side_dist->y = (ray->map_y + 1.0 - game->pos->y) * ray->delta_dist->y;
		}
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
