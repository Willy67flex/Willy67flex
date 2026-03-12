/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:09:32 by marvin            #+#    #+#             */
/*   Updated: 2025/11/13 13:09:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_args(t_stack *stack_a)
{
	if (stack_a->data[0] > stack_a->data[1])
		sa(stack_a, 1);
}

void	three_args(t_stack *stack_a)
{
	int	*s;

	s = stack_a->data;
	if (s[0] > s[1] && s[1] < s[2] && s[0] < s[2])
		sa(stack_a, 1);
	if (s[0] > s[1] && s[1] > s[2])
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	if (s[0] > s[1] && s[1] < s[2] && s[0] > s[2])
		ra(stack_a, 1);
	if (s[0] < s[1] && s[1] > s[2] && s[0] < s[2])
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	if (s[0] < s[1] && s[1] > s[2] && s[0] > s[2])
		rra(stack_a, 1);
}

void	four_args(t_stack *stack_a, t_stack *stack_b)
{
	int	lower_arg;
	int	pos;

	lower_arg = find_lower_arg(stack_a);
	pos = pos_lower_arg(stack_a, lower_arg);
	if (pos == -1)
		return ;
	put_lower_arg_pos_zero(stack_a, pos);
	if (check_good_order(stack_a) == 0)
		return ;
	pb (stack_a, stack_b, 1);
	three_args(stack_a);
	pa(stack_a, stack_b, 1);
}

void	five_args(t_stack *stack_a, t_stack *stack_b)
{
	int	lower_arg;
	int	pos;

	lower_arg = find_lower_arg(stack_a);
	pos = pos_lower_arg(stack_a, lower_arg);
	if (pos == -1)
		return ;
	put_lower_arg_pos_zero(stack_a, pos);
	if (check_good_order(stack_a) == 0)
		return ;
	pb (stack_a, stack_b, 1);
	four_args(stack_a, stack_b);
	pa(stack_a, stack_b, 1);
}

void	args_lt_5(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	if (stack_a->size == 2)
		two_args(stack_a);
	if (stack_a->size == 3)
		three_args(stack_a);
	if (stack_a->size == 4)
		four_args(stack_a, stack_b);
	if (stack_a->size == 5)
		five_args(stack_a, stack_b);
}
