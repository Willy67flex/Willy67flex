/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:24:30 by whollebe          #+#    #+#             */
/*   Updated: 2025/10/28 16:05:50 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_from_file(int fd, char *storage)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(storage), NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		if (ft_strchr_found(storage, '\n') == 1)
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(storage), NULL);
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			storage = ft_strjoin_and_free(storage, buffer);
			if (!storage)
				return (free(buffer), NULL);
		}
	}
	free(buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	storage = read_from_file(fd, storage);
	if (!storage || storage[0] == '\0')
		return (free(storage), storage = NULL, NULL);
	line = ft_extract_line(storage);
	if (!line)
		return (free(storage), storage = NULL, NULL);
	storage = ft_update_storage(storage);
	return (line);
}
