/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:04:40 by william           #+#    #+#             */
/*   Updated: 2025/12/15 17:30:15 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error_clean(t_game *game, char **tmp, char *msg)
{
	free_map(tmp, game->map_height);
	free_map(game->map, game->map_height);
	msg_error(msg);
}

void	flood_map(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	flood_map(map, x + 1, y);
	flood_map(map, x - 1, y);
	flood_map(map, x, y + 1);
	flood_map(map, x, y - 1);
}

void	get_player_pos(t_game *game, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				game->x = *x;
				game->y = *y;
				game->start_x = *x;
				game->start_y = *y;
				game->player_life = 3;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	check_path_and_free(t_game *game, char **tmp)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
		{
			if (tmp[i][j] == 'C')
				exit_error_clean(game, tmp, "Invalid map, item inaccessible");
			if (tmp[i][j] == 'E')
				exit_error_clean(game, tmp, "Invalid map, exit inaccessible");
		}
	}
	free_map(tmp, game->map_height);
}

void	verif_map(t_game *game)
{
	char	**tmp_map;
	int		i;
	int		p_x;
	int		p_y;

	tmp_map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!tmp_map)
		return ;
	i = -1;
	while (++i < game->map_height)
		tmp_map[i] = ft_strdup(game->map[i]);
	tmp_map[i] = NULL;
	get_player_pos(game, &p_x, &p_y);
	flood_map(tmp_map, p_x, p_y);
	check_path_and_free(game, tmp_map);
}
