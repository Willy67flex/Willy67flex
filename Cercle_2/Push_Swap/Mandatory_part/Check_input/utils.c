/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:38:28 by whollebe          #+#    #+#             */
/*   Updated: 2025/11/18 19:21:55 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (0);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

char	**ft_update_argv0(char **argv, int argc)
{
	char	**new_argv;
	int		i;
	int		j;
	int		p;

	p = -1;
	new_argv = malloc(sizeof(char *) * (argc + 1));
	if (!new_argv)
		return (NULL);
	i = 1;
	while (++p < argc)
	{
		j = 0;
		while (argv[i][j])
			j++;
		new_argv[p] = malloc(sizeof(char) * (j + 1));
		if (!new_argv[p])
			return (free_split(new_argv), NULL);
		j = -1;
		while (argv[i][++j])
			new_argv[p][j] = argv[i][j];
		new_argv[p][j] = '\0';
		i++;
	}
	return (new_argv[p] = NULL, new_argv);
}

int	init_stacks(t_stack *a_ptr, t_stack *b_ptr, int *array, int size)
{
	int	i;

	a_ptr->data = malloc(sizeof(int) * size);
	if (!a_ptr->data)
		return (0);
	i = 0;
	while (i < size)
	{
		a_ptr->data[i] = array[i];
		i++;
	}
	a_ptr->size = size;
	b_ptr->data = malloc(sizeof(int) * size);
	if (!b_ptr->data)
		return (free(a_ptr->data), 0);
	b_ptr->size = 0;
	return (1);
}
