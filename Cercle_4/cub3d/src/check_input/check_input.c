/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 10:21:31 by whollebe          #+#    #+#             */
/*   Updated: 2026/04/08 13:03:06 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_syntax(char *str, t_game *game)
{
	int	i;
	int	size;

	size = ft_strlen(str);
	if (size < 5)
		free_all(game, "Usage-> \"./cub3D path/to/the/map.cub\"");
	i = size - 4;
	if (strncmp(".cub\0", &str[i], 5) != 0)
		free_all(game, "Usage-> \"./cub3D path/to/the/map.cub\"");
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
		free_all(game, "Usage-> \"./cub3D path/to/the/map.cub\"");
	check_syntax(str, game);
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
