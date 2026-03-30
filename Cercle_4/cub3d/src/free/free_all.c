
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
	free(game->map_content->floor_color);
	free(game->map_content->ceiling_color);
	free(game->map_content);
}

void	free_texture(t_game *game)
{
	// free(game->texture->north);
	// free(game->texture->south);
	// free(game->texture->west);
	// free(game->texture->east);
	free(game->texture);
}

void	free_sprites(t_game *game)
{
	free(game->sprites);
}

void	free_all(t_game *game, char *msg)
{
	free_tab(game->map);
	free_map_content(game);
	free_texture(game);
	free_sprites(game);
	free(game->pos);
	free(game->dir);
	free(game->plane);
	// free(game->r_matrice);
	if (msg != NULL)
		msg_error(msg);
}
