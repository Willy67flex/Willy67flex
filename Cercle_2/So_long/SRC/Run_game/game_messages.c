/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_messages.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:01:42 by whollebe          #+#    #+#             */
/*   Updated: 2025/12/17 17:16:30 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_defeat(t_game *game)
{
	int	x;
	int	y;

	x = (game->map_width * IMG_SIZE) / 2;
	y = (game->map_height * IMG_SIZE) / 2;
	mlx_string_put(game->mlx, game->win, x - 30, y, 0xFFD700, "YOU LOST!");
	ft_printf("You lost in %d moves!\n", game->moves_count);
}

void	display_victory(t_game *game)
{
	int	x;
	int	y;

	x = (game->map_width * IMG_SIZE) / 2;
	y = (game->map_height * IMG_SIZE) / 2;
	mlx_string_put(game->mlx, game->win, x - 30, y, 0xFFD700, "YOU WIN !");
	ft_printf("You won in %d moves!\n", game->moves_count);
}
