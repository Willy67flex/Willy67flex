/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:07:41 by ele-moig          #+#    #+#             */
/*   Updated: 2026/03/31 14:07:54 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_map_content(t_game *game)
{
	free(game->map_content->n_txtr);
	free(game->map_content->s_txtr);
	free(game->map_content->w_txtr);
	free(game->map_content->e_txtr);
	free(game->map_content->door_txtr);
	free(game->map_content->floor_color);
	free(game->map_content->ceiling_color);
	free(game->map_content);
}

void	free_t_img(t_game *game, t_imgb *img)
{
	if (game->mlx && img && img->img)
		mlx_destroy_image(game->mlx, img->img);
}

void	free_texture(t_game *game)
{
	if (!game->texture)
		return ;
	free_t_img(game, &game->texture->north);
	free_t_img(game, &game->texture->south);
	free_t_img(game, &game->texture->west);
	free_t_img(game, &game->texture->east);
	free_t_img(game, &game->texture->door);
	free(game->texture);
}

void	free_all(t_game *game, char *msg)
{
	free_tab(game->map);
	free_map_content(game);
	free_texture(game);
	free(game->pos);
	free(game->dir);
	free(game->plane);
	if (game->ray)
	{
		free(game->ray->dir);
		free(game->ray->side_dist);
		free(game->ray->delta_dist);
		free(game->ray);
	}
	if (msg != NULL)
		msg_error(msg);
}
