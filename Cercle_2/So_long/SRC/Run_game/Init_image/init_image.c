/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:07:45 by whollebe          #+#    #+#             */
/*   Updated: 2025/12/17 11:41:09 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_images(t_game *game)
{
	init_image_player(game);
	init_image_heart(game);
	init_image_wall_and_grass(game);
	init_image_coin_and_exit(game);
	init_image_ennemy(game);
}
