/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:26:08 by marvin            #+#    #+#             */
/*   Updated: 2025/11/13 14:26:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_lower_arg(t_stack *stack_a)
{
	int	lower_arg;
	int	i;

	lower_arg = stack_a->data[0];
	i = 0;
	while (i < stack_a->size)
	{
		if (lower_arg > stack_a->data[i])
			lower_arg = stack_a->data[i];
		i++;
	}
	return (lower_arg);
}

int	pos_lower_arg(t_stack *stack_a, int lower_arg)
{
	int	*s;
	int	i;

	s = stack_a->data;
	i = 0;
	while (i < stack_a->size)
	{
		if (s[i] == lower_arg)
			return (i);
		i++;
	}
	return (-1);
}

int	pos_upper_arg(t_stack *stack_a)
{
	int	*s;
	int	lower_arg;
	int	i;

	lower_arg = stack_a->data[0];
	i = 0;
	while (i < stack_a->size)
	{
		if (lower_arg < stack_a->data[i])
			lower_arg = stack_a->data[i];
		i++;
	}
	s = stack_a->data;
	i = 0;
	while (i < stack_a->size)
	{
		if (s[i] == lower_arg)
			return (i);
		i++;
	}
	return (-1);
}

void	put_lower_arg_pos_zero(t_stack *stack_a, int pos)
{
	int	upper;

	upper = pos_upper_arg(stack_a);
	if (upper == -1)
		return ;
	if (pos == 0)
		return ;
	if (pos == 1 && upper == 0)
		ra(stack_a, 1);
	if (pos == 1 && upper != 0)
		sa(stack_a, 1);
	if (pos == 2)
	{
		ra(stack_a, 1);
		ra(stack_a, 1);
	}
	if (pos == 3 && stack_a->size == 4)
		rra(stack_a, 1);
	if (pos == 3 && stack_a->size == 5)
	{
		rra(stack_a, 1);
		rra(stack_a, 1);
	}
	if (pos == 4)
		rra(stack_a, 1);
}

int	check_good_order(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (i < stack_a->size - 1)
	{
		if (stack_a->data[i] > stack_a->data[i + 1])
			return (1);
		i++;
	}
	return (0);
}
