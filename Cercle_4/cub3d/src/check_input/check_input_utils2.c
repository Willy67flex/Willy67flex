/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:14:16 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/30 13:22:19 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_setting(t_game *game, int dir, int x, int y)
{
	game->map[y][x] = '0';
	game->player++;
	game->p_dir = dir;
	game->px = x;
	game->py = y;
	game->pos->x = x + 0.5;
	game->pos->y = y + 0.5;
	if (dir == 0)
	{
		game->dir->x = 0;
		game->dir->y = -1;
		game->plane->x = 0.85;
		game->plane->y = 0;
	}
	if (dir == 1)
	{
		game->dir->x = 0;
		game->dir->y = 1;
		game->plane->x = -0.85;
		game->plane->y = 0;
	}
	if (dir == 2)
	{
		game->dir->x = -1;
		game->dir->y = 0;
		game->plane->x = 0;
		game->plane->y = -0.85;
	}
	if (dir == 3)
	{
		game->dir->x = 1;
		game->dir->y = 0;
		game->plane->x = 0;
		game->plane->y = 0.85;
	}
}

void	scan_arg_map(t_game *game, int i, int  j)
{
	if (game->map[i][j] != 'N' && game->map[i][j] != 'S'
		&& game->map[i][j] != 'W' && game->map[i][j] != 'E'
		&& game->map[i][j] != '0' && game->map[i][j] != '1'
		&& game->map[i][j] != ' ' && game->map[i][j] != '\t'
		&& game->map[i][j] != '\0' && game->map[i][j] != 'D')
		free_all(game, "Invalide charactere in the map");
	if (game->map[i][j] == 'N')
		set_player_setting(game, 0, j, i);
	if (game->map[i][j] == 'S')
		set_player_setting(game, 1, j, i);
	if (game->map[i][j] == 'W')
		set_player_setting(game, 2, j, i);
	if (game->map[i][j] == 'E')
		set_player_setting(game, 3, j, i);
}

int	atocolor(char **str, t_game *game, int flag)
{
	int	x;

	x = ft_atoi(str[0]);
	if (x < 0 || x > 255)
		return (1);
	x = ft_atoi(str[1]);
	if (x < 0 || x > 255)
		return (1);
	x = ft_atoi(str[2]);
	if (x < 0 || x > 255)
		return (1);
	if (flag == 0)
		game->texture->hex_floor = get_rgb(ft_atoi(str[0]), ft_atoi(str[1]), ft_atoi(str[2]));
	else
		game->texture->hex_ceiling = get_rgb(ft_atoi(str[0]), ft_atoi(str[1]), ft_atoi(str[2]));
	return (0);
}

char	get_val(t_game *game, int y, int x)
{
	if (y < 0 || y >= game->map_height)
		return (' ');
	if (x < 0 || x >= (int)ft_strlen(game->map[y]))
		return (' ');
	if (game->map[y][x] == ' ' || game->map[y][x] == '\n')
		return (' ');
	return (game->map[y][x]);
}

int	is_playable_space(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == 'D')
		return (1);
	return (0);
}
