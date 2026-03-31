/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:09:41 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/31 14:20:09 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	assign_param(t_game *game, char *line, char *id, char **param)
{
	if (ft_strncmp(line, id, ft_strlen(id)) == 0)
	{
		if (*param)
			free_all(game, "Multiple definition of a parameter");
		*param = extract_path(line, ft_strlen(id));
		return (1);
	}
	return (0);
}

int	map_description(char *line, t_game *game)
{
	if (is_empty_line(line))
		return (0);
	if (assign_param(game, line, "NO ", &game->map_content->n_txtr) == 1)
		return (1);
	if (assign_param(game, line, "SO ", &game->map_content->s_txtr) == 1)
		return (1);
	if (assign_param(game, line, "WE ", &game->map_content->w_txtr) == 1)
		return (1);
	if (assign_param(game, line, "EA ", &game->map_content->e_txtr) == 1)
		return (1);
	if (assign_param(game, line, "D ", &game->map_content->door_txtr) == 1)
		return (1);
	if (assign_param(game, line, "F ", &game->map_content->floor_color) == 1)
		return (1);
	if (assign_param(game, line, "C ", &game->map_content->ceiling_color) == 1)
		return (1);
	if (!is_empty_line(line))
		free_all(game, "Invalid identifier in map description");
	return (0);
}

void	process_map_line(t_game *game, char *line, int *counts)
{
	if (counts[0] < 7)
		counts[0] += map_description(line, game);
	else if (is_empty_line(line) == 0)
	{
		if (counts[2] == 0)
			counts[2] = counts[1];
		game->map_height++;
	}
}

int	check_map_description(t_game *game, char *str)
{
	int		fd;
	char	*line;
	int		counts[3];

	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		free_all(game, "Cannot open file");
	line = get_next_line(fd);
	while (line != NULL)
	{
		process_map_line(game, line, counts);
		free(line);
		line = get_next_line(fd);
		counts[1]++;
	}
	return (close(fd), counts[2]);
}

void	fill_map(t_game *game, char *str, int start)
{
	int		fd;
	int		i;
	char	*line;

	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	fd = open(str, O_RDONLY);
	if (!game->map || fd < 0)
		free_all(game, "Error loading map");
	i = -1;
	while (++i < start)
		free(get_next_line(fd));
	i = -1;
	while (++i < game->map_height)
	{
		line = get_next_line(fd);
		if (is_empty_line(line))
			free_all(game, "Incorrect map");
		game->map[i] = ft_strdup(line);
		clean_newline(game->map[i]);
		free(line);
	}
	game->map[i] = NULL;
	clean_gnl(fd);
	close(fd);
}
