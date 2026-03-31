/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 09:47:52 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/31 14:12:39 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	open_door(t_game *game)
{
	int	check_x;
	int	check_y;

	check_x = (int)(game->pos->x + game->dir->x);
	check_y = (int)(game->pos->y + game->dir->y);
	if (game->map[check_y][check_x] == 'D')
		game->map[check_y][check_x] = 'E';
	else if (game->map[check_y][check_x] == 'E')
		game->map[check_y][check_x] = 'D';
}
