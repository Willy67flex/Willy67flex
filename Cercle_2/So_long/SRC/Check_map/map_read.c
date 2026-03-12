/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:02:24 by william           #+#    #+#             */
/*   Updated: 2025/12/02 16:33:18 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_line_len(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	return (len);
}

void	clean_exit(int fd, char *msg)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
	}
	close(fd);
	msg_error(msg);
}

int	process_map_lines(int fd, int width)
{
	char	*line;
	int		height;
	int		len;

	height = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len = get_line_len(line);
		free(line);
		if (len != width)
			clean_exit(fd, "The map is not rectangular");
		height++;
	}
	return (height);
}

void	define_length_and_width(t_game *game, char *ber)
{
	int		fd;
	char	*line;
	int		width;

	fd = open(ber, O_RDONLY);
	if (fd < 0)
		msg_error("Unable to open the file (fd < 0)");
	line = get_next_line(fd);
	if (!line)
		msg_error("Empty map or GNL reading error");
	width = get_line_len(line);
	free(line);
	if (width == 0)
	{
		close(fd);
		msg_error("The map cannot be empty or have a width of 0");
	}
	game->map_height = process_map_lines(fd, width);
	game->map_width = width;
	close(fd);
}

void	define_map(t_game *game, char *ber)
{
	int		fd;
	int		i;
	char	*line;

	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		msg_error("Malloc failed for map array");
	fd = open(ber, O_RDONLY);
	if (fd < 0)
		msg_error("Unable to open the file to fill map");
	i = 0;
	while (i < game->map_height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[game->map_width] == '\n')
			line[game->map_width] = '\0';
		game->map[i] = line;
		i++;
	}
	game->map[i] = NULL;
	get_next_line(fd);
	close(fd);
}
