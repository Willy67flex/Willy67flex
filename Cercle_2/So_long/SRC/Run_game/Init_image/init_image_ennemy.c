/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_ennemy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:17:36 by whollebe          #+#    #+#             */
/*   Updated: 2025/12/16 19:17:58 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_image_ennemy(t_game *game)
{
	game->sprites.enmy_down[0] = xpm_to_image(game, "img/ennemy_down_0.xpm");
	game->sprites.enmy_down[1] = xpm_to_image(game, "img/ennemy_down_1.xpm");
	game->sprites.enmy_down[2] = xpm_to_image(game, "img/ennemy_down_2.xpm");
	game->sprites.enmy_down[3] = xpm_to_image(game, "img/ennemy_down_3.xpm");
	game->sprites.enmy_up[0] = xpm_to_image(game, "img/ennemy_up_0.xpm");
	game->sprites.enmy_up[1] = xpm_to_image(game, "img/ennemy_up_1.xpm");
	game->sprites.enmy_up[2] = xpm_to_image(game, "img/ennemy_up_2.xpm");
	game->sprites.enmy_up[3] = xpm_to_image(game, "img/ennemy_up_3.xpm");
	game->sprites.enmy_left[0] = xpm_to_image(game, "img/ennemy_left_0.xpm");
	game->sprites.enmy_left[1] = xpm_to_image(game, "img/ennemy_left_1.xpm");
	game->sprites.enmy_left[2] = xpm_to_image(game, "img/ennemy_left_2.xpm");
	game->sprites.enmy_left[3] = xpm_to_image(game, "img/ennemy_left_3.xpm");
	game->sprites.enmy_right[0] = xpm_to_image(game, "img/ennemy_right_0.xpm");
	game->sprites.enmy_right[1] = xpm_to_image(game, "img/ennemy_right_1.xpm");
	game->sprites.enmy_right[2] = xpm_to_image(game, "img/ennemy_right_2.xpm");
	game->sprites.enmy_right[3] = xpm_to_image(game, "img/ennemy_right_3.xpm");
	game->sprites.current_frame_enmy = 0;
}
