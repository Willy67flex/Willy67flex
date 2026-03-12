/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:59:17 by whollebe          #+#    #+#             */
/*   Updated: 2025/12/17 13:49:19 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reset_pos_enemy(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->nb_enemy)
	{
		game->x_enemy[i] = game->start_x_enemy[i];
		game->y_enemy[i] = game->start_y_enemy[i];
		game->map[game->y_enemy[i]][game->x_enemy[i]] = 'M';
		i++;
	}
}

int	get_sign(int target, int current)
{
	if (target > current)
		return (1);
	if (target < current)
		return (-1);
	return (0);
}

int	is_valid_enemy_move(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1' || game->map[y][x] == 'E'
		|| game->map[y][x] == 'C' || game->map[y][x] == 'M')
		return (0);
	return (1);
}

void	update_single_enemy(t_game *game, int i, int new_x, int new_y)
{
	int	old_x;
	int	old_y;
	int	noise;

	old_x = game->x_enemy[i];
	old_y = game->y_enemy[i];
	if (new_x == game->x && new_y == game->y)
	{
		player_take_damage(game);
		return ;
	}
	game->map[old_y][old_x] = '0';
	noise = (old_x * 7) + (old_y * 13);
	put_img(game, game->texture.grass[noise % 3], old_x, old_y);
	game->x_enemy[i] = new_x;
	game->y_enemy[i] = new_y;
	game->map[new_y][new_x] = 'M';
}
