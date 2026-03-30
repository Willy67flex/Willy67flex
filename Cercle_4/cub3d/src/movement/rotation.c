/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:49:11 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/26 17:24:38 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotation_matrice(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->dir->x;
	old_plane_x = game->plane->x;
	game->dir->x = game->dir->x * cos(angle) - game->dir->y * sin(angle);
	game->dir->y = old_dir_x * sin(angle) + game->dir->y * cos(angle);
	game->plane->x = game->plane->x * cos(angle) - game->plane->y * sin(angle);
	game->plane->y = old_plane_x * sin(angle) + game->plane->y * cos(angle);
}
