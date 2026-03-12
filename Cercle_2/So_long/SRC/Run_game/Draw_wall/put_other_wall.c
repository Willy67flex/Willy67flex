/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_other_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:29:30 by whollebe          #+#    #+#             */
/*   Updated: 2025/12/17 13:30:06 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*put_special_wall(t_game *game, int x, int y, int max_y)
{
	int		up;
	int		down;
	int		left;
	int		right;

	up = (y > 0 && game->map[y - 1][x] == '1');
	down = (y < game->map_height - 1 && game->map[y + 1][x] == '1');
	left = (x > 0 && game->map[y][x - 1] == '1');
	right = (x < game->map_width - 1 && game->map[y][x + 1] == '1');
	if (y == max_y && up && !left && !right)
		return (game->texture.wall[2]);
	else if (y == max_y && up && left && !right)
		return (game->texture.corner_d_r[0]);
	else if (y == max_y && up && !left && right)
		return (game->texture.corner_d_l[0]);
	else if (y == max_y && !up && right && left)
		return (game->texture.wall_up[0]);
	else if (y == max_y && !up && left && !right)
		return (game->texture.corner_d_r[1]);
	else if (y == max_y && !up && !left && right)
		return (game->texture.corner_d_l[1]);
	else if (y == max_y && up && left && right)
		return (game->texture.wall_inter[0]);
	else
		return (NULL);
}

void	*put_horizontal_wall(t_game *game, int x, int y)
{
	int		up;
	int		down;
	int		left;
	int		right;
	void	*img;

	up = (y > 0 && game->map[y - 1][x] == '1');
	down = (y < game->map_height - 1 && game->map[y + 1][x] == '1');
	left = (x > 0 && game->map[y][x - 1] == '1');
	right = (x < game->map_width - 1 && game->map[y][x + 1] == '1');
	if (!up && !down && left && right)
		img = game->texture.wall_up[0];
	else if (!up && !down && !left && right)
		img = game->texture.corner_d_l[1];
	else if (!up && !down && left && !right)
		img = game->texture.corner_d_r[1];
	else
		return (NULL);
	return (img);
}

void	*put_vertical_wall(t_game *game, int x, int y)
{
	int		up;
	int		down;
	int		left;
	int		right;
	void	*img;

	up = (y > 0 && game->map[y - 1][x] == '1');
	down = (y < game->map_height - 1 && game->map[y + 1][x] == '1');
	left = (x > 0 && game->map[y][x - 1] == '1');
	right = (x < game->map_width - 1 && game->map[y][x + 1] == '1');
	if (up && down && !left && !right)
		img = game->texture.wall_left[0];
	else if (!up && down && !left && !right)
		img = game->texture.wall_up[1];
	else if (up && !down && !left && !right)
		img = game->texture.wall[2];
	else
		return (NULL);
	return (img);
}

void	*put_corner_wall(t_game *game, int x, int y)
{
	int		up;
	int		down;
	int		left;
	int		right;
	void	*img;

	up = (y > 0 && game->map[y - 1][x] == '1');
	down = (y < game->map_height - 1 && game->map[y + 1][x] == '1');
	left = (x > 0 && game->map[y][x - 1] == '1');
	right = (x < game->map_width - 1 && game->map[y][x + 1] == '1');
	if (down && right && !up && !left)
		img = game->texture.corner_u_l[0];
	else if (down && left && !up && !right)
		img = game->texture.corner_u_r[0];
	else if (up && right && !down && !left)
		img = game->texture.corner_d_l[0];
	else if (up && left && !down && !right)
		img = game->texture.corner_d_r[0];
	else
		return (NULL);
	return (img);
}

void	*put_intersection_wall(t_game *game, int x, int y)
{
	int		up;
	int		down;
	int		left;
	int		right;
	void	*img;

	up = (y > 0 && game->map[y - 1][x] == '1');
	down = (y < game->map_height - 1 && game->map[y + 1][x] == '1');
	left = (x > 0 && game->map[y][x - 1] == '1');
	right = (x < game->map_width - 1 && game->map[y][x + 1] == '1');
	if (up && down && left && right)
		img = game->texture.wall_inter[4];
	else if (up && !down && left && right)
		img = game->texture.wall_inter[0];
	else if (!up && down && left && right)
		img = game->texture.wall_inter[1];
	else if (up && down && left && !right)
		img = game->texture.wall_inter[2];
	else if (up && down && !left && right)
		img = game->texture.wall_inter[3];
	else
		img = game->texture.wall[3];
	return (img);
}
