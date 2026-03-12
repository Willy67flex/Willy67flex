/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:33:30 by whollebe          #+#    #+#             */
/*   Updated: 2025/12/17 13:30:06 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_sprite_array(t_game *game, void **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i])
		{
			mlx_destroy_image(game->mlx, arr[i]);
			arr[i] = NULL;
		}
		i++;
	}
}

static void	free_player_and_enemy(t_game *game)
{
	free_sprite_array(game, game->sprites.idle_down, 8);
	free_sprite_array(game, game->sprites.idle_up, 8);
	free_sprite_array(game, game->sprites.idle_left, 8);
	free_sprite_array(game, game->sprites.idle_right, 8);
	free_sprite_array(game, game->sprites.enmy_down, 4);
	free_sprite_array(game, game->sprites.enmy_up, 4);
	free_sprite_array(game, game->sprites.enmy_left, 4);
	free_sprite_array(game, game->sprites.enmy_right, 4);
}

static void	free_ui_and_items(t_game *game)
{
	free_sprite_array(game, game->sprites.b_heart, 5);
	free_sprite_array(game, game->sprites.heart, 5);
	free_sprite_array(game, game->sprites.coin, 10);
	free_sprite_array(game, game->texture.grass, 3);
	free_sprite_array(game, game->texture.exit, 2);
}

static void	free_walls(t_game *game)
{
	free_sprite_array(game, game->texture.wall, 4);
	free_sprite_array(game, game->texture.wall_right, 3);
	free_sprite_array(game, game->texture.wall_left, 3);
	free_sprite_array(game, game->texture.wall_up, 2);
	free_sprite_array(game, game->texture.wall_inter, 5);
	free_sprite_array(game, game->texture.corner_u_r, 3);
	free_sprite_array(game, game->texture.corner_u_l, 3);
	free_sprite_array(game, game->texture.corner_d_r, 3);
	free_sprite_array(game, game->texture.corner_d_l, 3);
}

void	destroy_all_images(t_game *game)
{
	free_player_and_enemy(game);
	free_ui_and_items(game);
	free_walls(game);
}
