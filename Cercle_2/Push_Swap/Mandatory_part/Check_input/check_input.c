/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:35:31 by whollebe          #+#    #+#             */
/*   Updated: 2025/11/18 15:08:04 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args_are_valid(char **args, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if (args[i][j] == '-' || args[i][j] == '+')
			j++;
		if (args[i][j] == '\0')
			return (1);
		while (args[i][j])
		{
			if (ft_isdigit(args[i][j++]) == 0)
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_args_are_int(long temp_long, int *result, int count, char **str)
{
	int	i;

	i = -1;
	while (++i < count)
	{
		temp_long = ft_atol(str[i]);
		if (temp_long > 2147483647 || temp_long < -2147483648)
			return (1);
		result[i] = (int)temp_long;
	}
	return (0);
}

int	check_doublons(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
