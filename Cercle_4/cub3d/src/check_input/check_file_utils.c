/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 10:09:41 by whollebe          #+#    #+#             */
/*   Updated: 2026/04/08 13:24:40 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	assign_param(char *line, char *id, char **param)
{
	if (ft_strncmp(line, id, ft_strlen(id)) == 0)
	{
		if (*param)
			return (2);
		*param = extract_path(line, ft_strlen(id));
		return (1);
	}
	return (0);
}

int	check_param(char *line, t_game *game)
{
	int	result;

	result = assign_param(line, "NO ", &game->map_content->n_txtr);
	if (result == 0)
		result = assign_param(line, "SO ", &game->map_content->s_txtr);
	if (result == 0)
		result = assign_param(line, "WE ", &game->map_content->w_txtr);
	if (result == 0)
		result = assign_param(line, "EA ", &game->map_content->e_txtr);
	if (result == 0)
		result = assign_param(line, "D ", &game->map_content->door_txtr);
	if (result == 0)
		result = assign_param(line, "F ", &game->map_content->floor_color);
	if (result == 0)
		result = assign_param(line, "C ", &game->map_content->ceiling_color);
	return (result);
}

void	skipping_lines(int start, int fd)
{
	int	i;

	i = -1;
	while (++i < start)
		free(get_next_line(fd));
}

void	handle_empty_map_line(t_game *game, char *line, int fd)
{
	if (is_empty_line(line))
	{
		free(line);
		clean_gnl(fd);
		close(fd);
		free_all(game, "Incorrect map");
	}
}
