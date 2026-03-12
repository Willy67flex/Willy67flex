/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:10:00 by whollebe          #+#    #+#             */
/*   Updated: 2025/12/16 19:20:09 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_image_player_down(t_game *game)
{
	game->sprites.idle_down[0] = xpm_to_image(game, "img/player_down_0.xpm");
	game->sprites.idle_down[1] = xpm_to_image(game, "img/player_down_1.xpm");
	game->sprites.idle_down[2] = xpm_to_image(game, "img/player_down_2.xpm");
	game->sprites.idle_down[3] = xpm_to_image(game, "img/player_down_3.xpm");
	game->sprites.idle_down[4] = xpm_to_image(game, "img/player_down_4.xpm");
	game->sprites.idle_down[5] = xpm_to_image(game, "img/player_down_5.xpm");
	game->sprites.idle_down[6] = xpm_to_image(game, "img/player_down_6.xpm");
	game->sprites.idle_down[7] = xpm_to_image(game, "img/player_down_7.xpm");
}

void	init_image_player_up(t_game *game)
{
	game->sprites.idle_up[0] = xpm_to_image(game, "img/player_up_0.xpm");
	game->sprites.idle_up[1] = xpm_to_image(game, "img/player_up_1.xpm");
	game->sprites.idle_up[2] = xpm_to_image(game, "img/player_up_2.xpm");
	game->sprites.idle_up[3] = xpm_to_image(game, "img/player_up_3.xpm");
	game->sprites.idle_up[4] = xpm_to_image(game, "img/player_up_4.xpm");
	game->sprites.idle_up[5] = xpm_to_image(game, "img/player_up_5.xpm");
	game->sprites.idle_up[6] = xpm_to_image(game, "img/player_up_6.xpm");
	game->sprites.idle_up[7] = xpm_to_image(game, "img/player_up_7.xpm");
}

void	init_image_player_left(t_game *game)
{
	game->sprites.idle_left[0] = xpm_to_image(game, "img/player_left_0.xpm");
	game->sprites.idle_left[1] = xpm_to_image(game, "img/player_left_1.xpm");
	game->sprites.idle_left[2] = xpm_to_image(game, "img/player_left_2.xpm");
	game->sprites.idle_left[3] = xpm_to_image(game, "img/player_left_3.xpm");
	game->sprites.idle_left[4] = xpm_to_image(game, "img/player_left_4.xpm");
	game->sprites.idle_left[5] = xpm_to_image(game, "img/player_left_5.xpm");
	game->sprites.idle_left[6] = xpm_to_image(game, "img/player_left_6.xpm");
	game->sprites.idle_left[7] = xpm_to_image(game, "img/player_left_7.xpm");
}

void	init_image_player_right(t_game *game)
{
	game->sprites.idle_right[0] = xpm_to_image(game, "img/player_right_0.xpm");
	game->sprites.idle_right[1] = xpm_to_image(game, "img/player_right_1.xpm");
	game->sprites.idle_right[2] = xpm_to_image(game, "img/player_right_2.xpm");
	game->sprites.idle_right[3] = xpm_to_image(game, "img/player_right_3.xpm");
	game->sprites.idle_right[4] = xpm_to_image(game, "img/player_right_4.xpm");
	game->sprites.idle_right[5] = xpm_to_image(game, "img/player_right_5.xpm");
	game->sprites.idle_right[6] = xpm_to_image(game, "img/player_right_6.xpm");
	game->sprites.idle_right[7] = xpm_to_image(game, "img/player_right_7.xpm");
}

void	init_image_player(t_game *game)
{
	game->sprites.current_frame = 0;
	game->sprites.direction = DIR_DOWN;
	init_image_player_down(game);
	init_image_player_up(game);
	init_image_player_left(game);
	init_image_player_right(game);
}
