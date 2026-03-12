/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:16:05 by whollebe          #+#    #+#             */
/*   Updated: 2025/10/28 16:05:05 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_from_file_bonus(int fd, char *storage_fd)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(storage_fd), NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		if (ft_strchr_found(storage_fd, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(storage_fd), NULL);
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			storage_fd = ft_strjoin_and_free(storage_fd, buffer);
			if (!storage_fd)
				return (free(buffer), NULL);
		}
	}
	free(buffer);
	return (storage_fd);
}

char	*get_next_line(int fd)
{
	static char	*storage[1024];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= 1024)
		return (NULL);
	storage[fd] = read_from_file_bonus(fd, storage[fd]);
	if (!storage[fd] || storage[fd][0] == '\0')
	{
		free(storage[fd]);
		storage[fd] = NULL;
		return (NULL);
	}
	line = ft_extract_line(storage[fd]);
	if (!line)
	{
		free(storage[fd]);
		storage[fd] = NULL;
		return (NULL);
	}
	storage[fd] = ft_update_storage(storage[fd]);
	return (line);
}
