/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:58:08 by william           #+#    #+#             */
/*   Updated: 2025/12/17 12:37:50 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	run_game(t_game *game)
{
	init_window(game);
	init_images(game);
	render_map(game);
	mlx_loop_hook(game->mlx, animation_loop, game);
	mlx_loop(game->mlx);
	free_map(game->map, game->map_height);
}
