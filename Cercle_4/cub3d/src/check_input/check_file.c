/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:09:41 by whollebe          #+#    #+#             */
/*   Updated: 2026/04/08 14:24:24 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_description(char *line, t_game *game, int fd)
{
	int	result;

	if (is_empty_line(line))
		return (0);
	result = check_param(line, game);
	if (result == 2 || result == 0)
	{
		free(line);
		clean_gnl(fd);
		close(fd);
		if (result == 2)
			free_all(game, "Multiple definition of a parameter");
		free_all(game, "Invalid identifier in map description");
	}
	return (result == 1);
}

void	process_map_line(t_game *game, char *line, int *counts, int fd)
{
	if (counts[0] < 7)
		counts[0] += map_description(line, game, fd);
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
		process_map_line(game, line, counts, fd);
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

	game->map = ft_calloc(sizeof(char *), (game->map_height + 1));
	fd = open(str, O_RDONLY);
	if (!game->map || fd < 0)
		free_all(game, "Error loading map");
	skipping_lines(start, fd);
	i = -1;
	while (++i < game->map_height)
	{
		line = get_next_line(fd);
		handle_empty_map_line(game, line, fd);
		game->map[i] = ft_strdup(line);
		clean_newline(game->map[i]);
		free(line);
	}
	clean_gnl(fd);
	close(fd);
}
