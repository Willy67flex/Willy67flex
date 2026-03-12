/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_wall_and_grass.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:15:00 by whollebe          #+#    #+#             */
/*   Updated: 2025/12/17 13:38:48 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_image_wall_and_grass(t_game *game)
{
	game->texture.corner_d_l[0] = xpm_to_image(game, "img/corner_D_L_0.xpm");
	game->texture.corner_d_l[1] = xpm_to_image(game, "img/corner_D_L_1.xpm");
	game->texture.corner_d_l[2] = xpm_to_image(game, "img/corner_D_L_2.xpm");
	game->texture.corner_d_r[0] = xpm_to_image(game, "img/corner_D_R_0.xpm");
	game->texture.corner_d_r[1] = xpm_to_image(game, "img/corner_D_R_1.xpm");
	game->texture.corner_d_r[2] = xpm_to_image(game, "img/corner_D_R_2.xpm");
	game->texture.corner_u_l[0] = xpm_to_image(game, "img/corner_U_L_0.xpm");
	game->texture.corner_u_r[0] = xpm_to_image(game, "img/corner_U_R_0.xpm");
	game->texture.grass[0] = xpm_to_image(game, "img/grass_0.xpm");
	game->texture.grass[1] = xpm_to_image(game, "img/grass_1.xpm");
	game->texture.grass[2] = xpm_to_image(game, "img/grass_2.xpm");
	game->texture.wall[0] = xpm_to_image(game, "img/wall_0.xpm");
	game->texture.wall[1] = xpm_to_image(game, "img/wall_1.xpm");
	game->texture.wall[3] = xpm_to_image(game, "img/wall_3.xpm");
	game->texture.wall[2] = xpm_to_image(game, "img/wall_one_wide.xpm");
	game->texture.wall_left[0] = xpm_to_image(game, "img/wall_left.xpm");
	game->texture.wall_right[0] = xpm_to_image(game, "img/wall_right.xpm");
	game->texture.wall_up[0] = xpm_to_image(game, "img/wall_up.xpm");
	game->texture.wall_up[1] = xpm_to_image(game, "img/wall_up_0.xpm");
	game->texture.wall_inter[0] = xpm_to_image(game, "img/wall_inter_0.xpm");
	game->texture.wall_inter[1] = xpm_to_image(game, "img/wall_inter_1.xpm");
	game->texture.wall_inter[2] = xpm_to_image(game, "img/wall_inter_2.xpm");
	game->texture.wall_inter[3] = xpm_to_image(game, "img/wall_inter_3.xpm");
	game->texture.wall_inter[4] = xpm_to_image(game, "img/wall_inter_4.xpm");
}
