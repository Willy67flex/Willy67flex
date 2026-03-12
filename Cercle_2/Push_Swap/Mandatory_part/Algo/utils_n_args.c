/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_n_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:39:13 by whollebe          #+#    #+#             */
/*   Updated: 2025/11/18 15:08:45 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_nearly_sorted(t_stack *stack)
{
	int	i;
	int	break_count;

	i = 0;
	break_count = 0;
	while (i < stack->size - 1)
	{
		if (stack->data[i] > stack->data[i + 1])
			break_count++;
		i++;
	}
	if (stack->data[stack->size - 1] > stack->data[0])
		break_count++;
	return (break_count <= 1);
}

int	find_max_index(t_stack *stack)
{
	int	i;
	int	max_index;
	int	max_value;

	i = 0;
	max_index = -1;
	max_value = -2147483648;
	while (i < stack->size)
	{
		if (stack->data[i] > max_value)
		{
			max_value = stack->data[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

int	find_min_index(t_stack *stack)
{
	int	i;
	int	min_index;
	int	min_value;

	i = 0;
	min_index = -1;
	min_value = 2147483647;
	while (i < stack->size)
	{
		if (stack->data[i] < min_value)
		{
			min_value = stack->data[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int	abs_val(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
