/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:13:51 by ele-moig          #+#    #+#             */
/*   Updated: 2025/10/30 14:30:01 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*stash;
	static char	*leftover;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	stash = fill_buffer(fd, buffer, &leftover);
	free(buffer);
	buffer = NULL;
	if (!stash)
		return (NULL);
	leftover = trim_line(stash);
	return (stash);
}

char	*fill_buffer(int fd, char *buffer, char **leftover)
{
	ssize_t	buff_return;
	char	*tmp;

	buff_return = 1;
	while (buff_return > 0)
	{
		buff_return = read(fd, buffer, BUFFER_SIZE);
		if (buff_return < 0)
		{
			free(*leftover);
			*leftover = NULL;
			return (NULL);
		}
		else if (buff_return == 0)
			break ;
		buffer[buff_return] = '\0';
		if (!*leftover)
			*leftover = ft_strdup("");
		tmp = *leftover;
		*leftover = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (*leftover);
}

char	*trim_line(char *to_trim)
{
	int		i;
	char	*leftover;

	i = 0;
	while (to_trim[i] != '\n' && to_trim[i] != '\0')
		i++;
	if (to_trim[i] == '\0')
		return (NULL);
	leftover = ft_substr(to_trim, i + 1, ft_strlen(to_trim) - (i + 1));
	if (*leftover == '\0')
	{
		free(leftover);
		leftover = NULL;
	}
	to_trim[i + 1] = '\0';
	return (leftover);
}

// int	main(void)
// {
// 	int i = 0;
// 	int fd = open("test_text.txt", O_RDONLY);
// 	char *to_print;

// 	while (i != 5)
// 	{
// 		to_print = get_next_line(fd);
// 		printf("loop nbr %d: %s", i, to_print);
// 		i++;
// 	}
// }
