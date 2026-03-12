/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_args.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:53:03 by whollebe          #+#    #+#             */
/*   Updated: 2025/11/18 18:44:06 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_back_to_a(t_stack *a, t_stack *b)
{
	int	target_idx;
	int	cost;

	while (b->size > 0)
	{
		find_target_in_a(a, b->data[0], &target_idx);
		if (target_idx <= a->size / 2)
			cost = target_idx;
		else
			cost = target_idx - a->size;
		while (cost > 0)
		{
			ra(a, 1);
			cost--;
		}
		while (cost < 0)
		{
			rra(a, 1);
			cost++;
		}
		pa(a, b, 1);
	}
}

void	final_sort(t_stack *a)
{
	int	min_idx;
	int	cost;

	min_idx = find_min_index(a);
	if (min_idx <= a->size / 2)
		cost = min_idx;
	else
		cost = min_idx - a->size;
	while (cost > 0)
	{
		ra(a, 1);
		cost--;
	}
	while (cost < 0)
	{
		rra(a, 1);
		cost++;
	}
}

void	n_args(t_stack *stack_a, t_stack *stack_b)
{
	if (check_good_order(stack_a) == 0)
		return ;
	index_stack(stack_a);
	if (is_nearly_sorted(stack_a) == 1)
	{
		final_sort(stack_a);
		return ;
	}
	pb(stack_a, stack_b, 1);
	pb(stack_a, stack_b, 1);
	while (stack_a->size > 3)
		execute_cheapest_move(stack_a, stack_b);
	if (check_good_order(stack_a) != 0)
		three_args(stack_a);
	move_back_to_a(stack_a, stack_b);
	final_sort(stack_a);
}
