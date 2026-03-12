/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:59:15 by william           #+#    #+#             */
/*   Updated: 2025/12/17 15:05:46 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_char(t_char *character)
{
	character->c = 0;
	character->e = 0;
	character->o = 0;
	character->p = 0;
	character->wall = 0;
	character->m = 0;
}

void	scan_char(char c, t_char *character)
{
	if (c == '0')
		character->o++;
	else if (c == 'E')
		character->e++;
	else if (c == 'C')
		character->c++;
	else if (c == 'P')
		character->p++;
	else if (c == '1')
		character->wall++;
	else if (c == 'M')
		character->m++;
	else if (c == 0 || c == '\n')
		return ;
	else
		msg_error("invalid character in the map");
}

void	scan_map(t_game *game, t_char *character)
{
	int	i;
	int	j;

	i = -1;
	init_char(character);
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
		{
			scan_char(game->map[i][j], character);
			if (game->map[i][j] == 'P')
			{
				game->start_x = j;
				game->start_y = i;
				game->x = j;
				game->y = i;
			}
		}
	}
	game->collectibles = character->c;
	game->total_collectibles = character->c;
	game->moves_count = 0;
	get_enemies_pos(game, character);
}

void	verif_char(t_game *game, t_char *character)
{
	int	i;

	i = 0;
	if (character->e != 1)
		msg_error("multiple definition of the exit");
	if (character->p != 1)
		msg_error("multiple definition of starting position");
	if (!(character->c >= 1))
		msg_error("we need to have at least one collectible");
	verif_enemy(character);
	while (i < game->map_width)
	{
		if (game->map[0][i] != '1' || game->map[game->map_height - 1][i] != '1')
			msg_error("Map is not closed by walls (top/bottom)");
		i++;
	}
	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->map_width - 1] != '1')
			msg_error("Map is not closed by walls (sides)");
		i++;
	}
	printf("nombres de 0 : %d\n", character->o);
}

void	check_map(char *ber, t_game *game, t_char *character)
{
	define_length_and_width(game, ber);
	define_map(game, ber);
	scan_map(game, character);
	verif_char(game, character);
	verif_map(game);
}
