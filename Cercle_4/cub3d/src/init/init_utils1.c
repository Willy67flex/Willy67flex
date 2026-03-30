

#include "cub3d.h"

void	init_game(t_game *game)
{
	game->map_content = malloc(sizeof(t_map_content));
	game->texture = malloc(sizeof(t_texture));
	game->sprites = malloc(sizeof(t_sprites));
	game->pos = malloc(sizeof(t_vec2));
	game->dir = malloc(sizeof(t_vec2));
	game->plane = malloc(sizeof(t_vec2));
	game->map = NULL;
	game->p_dir = 0;
	game->player = 0;
	game->px = 0;
	game->py = 0;
	game->dir->x = 0;
	game->dir->y = 0;
	init_ray(game);
	init_map_cont(game);
	init_texture(game);
	game->mlx = mlx_init();
	game->key_a = 0;
	game->key_w = 0;
	game->key_s = 0;
	game->key_d = 0;
	game->key_shift = 0;
	game->key_left = 0;
	game->key_right = 0;
}

void	init_map_cont(t_game *game)
{
	game->map_content->n_txtr = NULL;
	game->map_content->s_txtr = NULL;
	game->map_content->w_txtr = NULL;
	game->map_content->e_txtr = NULL;
	game->map_content->floor_color = NULL;
	game->map_content->ceiling_color = NULL;
}

void init_ray(t_game	*game)
{
	game->ray = malloc(sizeof(t_ray));
	game->ray->dir = malloc(sizeof(t_vec2));
	game->ray->side_dist = malloc(sizeof(t_vec2));
	game->ray->delta_dist = malloc(sizeof(t_vec2));
}

void init_texture(t_game *game)
{
	game->texture->hex_floor = 0;
	game->texture->hex_ceiling = 0;
}

void	init_all_textures(t_game *game)
{
	xpm_to_image(game, &game->texture->north, game->map_content->n_txtr);
	xpm_to_image(game, &game->texture->south, game->map_content->s_txtr);
	xpm_to_image(game, &game->texture->west, game->map_content->w_txtr);
	xpm_to_image(game, &game->texture->east, game->map_content->e_txtr);
}