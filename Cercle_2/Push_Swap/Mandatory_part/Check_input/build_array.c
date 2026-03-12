/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:25:54 by whollebe          #+#    #+#             */
/*   Updated: 2025/11/18 19:21:42 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*build_array_whith_str(char *str, int *argc)
{
	char	**new_str;
	int		*result_tab;
	long	temp_long;
	int		i;

	temp_long = 0;
	new_str = ft_split(str, ' ');
	if (!new_str)
		return (NULL);
	i = 0;
	while (new_str[i])
		i++;
	*argc = i;
	if (check_args_are_valid(new_str, *argc) == 1)
		return (free_split(new_str), NULL);
	result_tab = malloc(sizeof(int) * *argc);
	if (!result_tab)
		return (free_split(new_str), NULL);
	if (check_args_are_int(temp_long, result_tab, *argc, new_str) == 1)
		return (free_split(new_str), free(result_tab), NULL);
	if (check_doublons(result_tab, *argc) == 1)
		return (free_split(new_str), free(result_tab), NULL);
	return (free_split(new_str), result_tab);
}

int	*built_array_with_n_args(char **argv, int argc)
{
	char	**str_tab;
	int		*result_tab;
	long	temp_long;
	int		count;

	temp_long = 0;
	count = argc;
	str_tab = ft_update_argv0(argv, count);
	if (!str_tab)
		return (NULL);
	if (check_args_are_valid(str_tab, count) == 1)
		return (free_split(str_tab), NULL);
	result_tab = malloc(sizeof(int) * count);
	if (!result_tab)
		return (free_split(str_tab), NULL);
	if (check_args_are_int(temp_long, result_tab, count, str_tab) == 1)
		return (free_split(str_tab), free(result_tab), NULL);
	if (check_doublons(result_tab, count) == 1)
		return (free_split(str_tab), free(result_tab), NULL);
	return (free_split(str_tab), result_tab);
}

int	*handle_input(int argc, char **argv, int *count)
{
	int	*array;

	array = NULL;
	if (argc == 2)
	{
		array = build_array_whith_str(argv[1], count);
		if (!array)
			return (NULL);
	}
	else if (argc > 2)
	{
		*count = argc - 1;
		array = built_array_with_n_args(argv, *count);
		if (!array)
			return (NULL);
	}
	return (array);
}
