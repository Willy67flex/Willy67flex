/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:37:00 by whollebe          #+#    #+#             */
/*   Updated: 2025/11/18 18:43:34 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_remaining_a_rotations(t_stack *a, int cost_a)
{
	while (cost_a > 0)
	{
		ra(a, 1);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(a, 1);
		cost_a++;
	}
}

void	execute_remaining_b_rotations(t_stack *b, int cost_b)
{
	while (cost_b > 0)
	{
		rb(b, 1);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(b, 1);
		cost_b++;
	}
}

void	execute_rotations(t_stack *a, t_stack *b, t_cost cost)
{
	while (cost.a > 0 && cost.b > 0)
	{
		rr(a, b, 1);
		cost.a--;
		cost.b--;
	}
	while (cost.a < 0 && cost.b < 0)
	{
		rrr(a, b, 1);
		cost.a++;
		cost.b++;
	}
	execute_remaining_a_rotations(a, cost.a);
	execute_remaining_b_rotations(b, cost.b);
}

t_cost	find_cheapest_move(t_stack *a, t_stack *b, int *best_move_idx)
{
	t_cost	cheapest_cost;
	t_cost	current_costs;
	int		i;

	i = 0;
	cheapest_cost.total = 2147483647;
	while (i < a->size)
	{
		calculate_costs(a, b, i, &current_costs);
		if (current_costs.total < cheapest_cost.total)
		{
			cheapest_cost = current_costs;
			*best_move_idx = i;
		}
		i++;
	}
	return (cheapest_cost);
}

void	execute_cheapest_move(t_stack *a, t_stack *b)
{
	t_cost	standard_cost;
	t_cost	swap_cost;
	int		best_move_idx;

	standard_cost = find_cheapest_move(a, b, &best_move_idx);
	swap_cost = calculate_swap_cost(a, b);
	if (swap_cost.total < standard_cost.total)
	{
		sa(a, 1);
		execute_rotations(a, b, swap_cost);
	}
	else
	{
		calculate_costs(a, b, best_move_idx, &standard_cost);
		execute_rotations(a, b, standard_cost);
	}
	pb(a, b, 1);
}
