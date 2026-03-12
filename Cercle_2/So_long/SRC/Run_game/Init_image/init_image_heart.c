/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_heart.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:13:53 by whollebe          #+#    #+#             */
/*   Updated: 2025/12/16 19:19:55 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_image_heart(t_game *game)
{
	int	map_w_px;

	map_w_px = game->map_width * IMG_SIZE;
	game->sprites.frame_heart = 0;
	game->sprites.pos_first_heart = map_w_px - (3 * IMG_SIZE);
	game->sprites.pos_second_heart = map_w_px - (2 * IMG_SIZE);
	game->sprites.pos_third_heart = map_w_px - (1 * IMG_SIZE);
	game->sprites.current_state_first_heart = 1;
	game->sprites.current_state_second_heart = 1;
	game->sprites.current_state_third_heart = 1;
	game->sprites.break_cnt_1 = 0;
	game->sprites.break_cnt_2 = 0;
	game->sprites.break_cnt_3 = 0;
	game->sprites.heart[0] = xpm_to_image(game, "img/heart_0.xpm");
	game->sprites.heart[1] = xpm_to_image(game, "img/heart_1.xpm");
	game->sprites.heart[2] = xpm_to_image(game, "img/heart_2.xpm");
	game->sprites.heart[3] = xpm_to_image(game, "img/heart_3.xpm");
	game->sprites.heart[4] = xpm_to_image(game, "img/heart_4.xpm");
	game->sprites.b_heart[0] = xpm_to_image(game, "img/b_heart_0.xpm");
	game->sprites.b_heart[1] = xpm_to_image(game, "img/b_heart_1.xpm");
	game->sprites.b_heart[2] = xpm_to_image(game, "img/b_heart_2.xpm");
	game->sprites.b_heart[3] = xpm_to_image(game, "img/b_heart_3.xpm");
	game->sprites.b_heart[4] = xpm_to_image(game, "img/b_heart_4.xpm");
}
