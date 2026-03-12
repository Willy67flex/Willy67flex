/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:43:52 by william           #+#    #+#             */
/*   Updated: 2025/12/18 09:14:51 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	msg_error(char *msg)
{
	ft_printf("Error\n%s\n", msg);
	exit(EXIT_FAILURE);
}

void	check_input(int argc, char **argv)
{
	int	size;
	int	i;

	if (argc != 2)
		msg_error("Usage-> ./so_long \"Map/<map>.ber\"");
	size = ft_strlen(argv[1]);
	if (size < 5)
		msg_error("Usage-> ./so_long \"Map/<map>.ber\"");
	i = size - 4;
	if (strncmp(".ber\0", &argv[1][i], 5) != 0)
		msg_error("Usage-> ./so_long \"Map/<map>.ber\"");
}
