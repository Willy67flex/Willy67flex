/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_coin_and_exit.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:17:02 by whollebe          #+#    #+#             */
/*   Updated: 2025/12/16 19:17:20 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_image_coin_and_exit(t_game *game)
{
	game->sprites.coin[0] = xpm_to_image(game, "img/coin_0.xpm");
	game->sprites.coin[1] = xpm_to_image(game, "img/coin_1.xpm");
	game->sprites.coin[2] = xpm_to_image(game, "img/coin_2.xpm");
	game->sprites.coin[3] = xpm_to_image(game, "img/coin_3.xpm");
	game->sprites.coin[4] = xpm_to_image(game, "img/coin_4.xpm");
	game->sprites.coin[5] = xpm_to_image(game, "img/coin_5.xpm");
	game->sprites.coin[6] = xpm_to_image(game, "img/coin_6.xpm");
	game->sprites.coin[7] = xpm_to_image(game, "img/coin_7.xpm");
	game->sprites.coin[8] = xpm_to_image(game, "img/coin_8.xpm");
	game->sprites.coin[9] = xpm_to_image(game, "img/coin_9.xpm");
	game->sprites.frame_coin = 0;
	game->texture.exit[0] = xpm_to_image(game, "img/exit_0.xpm");
	game->texture.exit[1] = xpm_to_image(game, "img/exit_1.xpm");
}
