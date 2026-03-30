
#include "cub3d.h"

/*
le flag est pour savoir si on enregistre la couleur ou l'on est dans hex_floor
ou hex_ceilling, si il est egual a 0, on le met dans hex_floor, et si c'est 1,
dans hex_ceiling.
*/
int	check_description_color(char *color, t_game *game, int flag)
{
	char	**char_color;

	if (count_char(color, ',') != 2)
		return (1);
	char_color = ft_split(color, ',');
	if (!char_color)
		return (1);
	if (char_table_len(char_color) != 3)
		return (free_tab(char_color), 1);
	if (is_valid_number_format(char_color[0]) ||
		is_valid_number_format(char_color[1]) ||
		is_valid_number_format(char_color[2]))
		return (free_tab(char_color), 1);
	if (atocolor(char_color, game, flag))
		return (free_tab(char_color), 1);
	free_tab(char_color);
	return (0);
}

void	scan_description(t_game *game)
{
	if (check_texture_exists(game->map_content->n_txtr))
		free_all(game, "Failed to load NO texture-> File missing or invalid");
	if (check_texture_exists(game->map_content->s_txtr))
		free_all(game, "Failed to load SO texture-> File missing or invalid");
	if (check_texture_exists(game->map_content->w_txtr))
		free_all(game, "Failed to load WE texture-> File missing or invalid");
	if (check_texture_exists(game->map_content->e_txtr))
		free_all(game, "Failed to load EA texture-> File missing or invalid");
	if (check_description_color(game->map_content->floor_color, game, 0))
		free_all(game, "Invalid color for the floor");
	if (check_description_color(game->map_content->ceiling_color, game, 1))
		free_all(game, "Invalid color for the ceiling");
}

int	check_surrounded(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (is_playable_space(game->map[y][x]))
			{
				if (get_val(game, y - 1, x) == ' ' ||
					get_val(game, y + 1, x) == ' ' ||
					get_val(game, y, x - 1) == ' ' ||
					get_val(game, y, x + 1) == ' ')
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	xpm_to_image(t_game *game, t_imgb *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(game->mlx, path, &tex->width, &tex->height);
	if (!tex->img)
		free_all(game, "Impossible to load textures");
	tex->addr = mlx_get_data_addr(tex->img, &tex->bbp, &tex->line_length, &tex->endian);
}

void	scan_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	scan_description(game);
	init_all_textures(game);
	if (check_surrounded(game))
		free_all(game, "The map is not closed by walls!");
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			scan_arg_map(game, i, j);
			j++;
		}
		i++;
	}
	if (game->player < 1)
		free_all(game, "Undefined player");
	if (game->player > 1)
		free_all(game, "Multiple definition of the player");
}


