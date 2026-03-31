/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 10:21:31 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/31 13:29:12 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_syntax(char *str)
{
	int	i;
	int	size;

	size = ft_strlen(str);
	if (size < 5)
		msg_error("Usage-> \"./cub3D path/to/the/map.cub\"");
	i = size - 4;
	if (strncmp(".cub\0", &str[i], 5) != 0)
		msg_error("Usage-> \"./cub3D path/to/the/map.cub\"");
}

void	check_file(t_game *game, char *str)
{
	int	line;

	game->map_height = 0;
	line = check_map_description(game, str);
	fill_map(game, str, line);
	scan_map(game);
}

void	check_input(char *str, t_game *game, int argc)
{
	if (argc != 2)
		msg_error("Usage-> \"./cub3D path/to/the/map.cub\"");
	check_syntax(str);
	check_file(game, str);
}

void	set_vect_dir(t_game *game, double x, double y)
{
	game->dir->x = x;
	game->dir->y = y;
}

void	set_vect_plane(t_game *game, double x, double y)
{
	game->plane->x = x;
	game->plane->y = y;
}
