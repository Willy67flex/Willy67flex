/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:35:45 by whollebe          #+#    #+#             */
/*   Updated: 2025/11/18 15:08:20 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_target_in_b(t_stack *a, t_stack *b, int a_idx, int *target_idx)
{
	int	i;
	int	curr_a_val;
	int	best_target_val;

	curr_a_val = a->data[a_idx];
	best_target_val = -2147483648;
	*target_idx = -1;
	i = 0;
	while (i < b->size)
	{
		if (b->data[i] < curr_a_val && b->data[i] > best_target_val)
		{
			best_target_val = b->data[i];
			*target_idx = i;
		}
		i++;
	}
	if (*target_idx == -1)
		*target_idx = find_max_index(b);
}

void	find_target_in_a(t_stack *a, int b_val, int *target_idx)
{
	int	i;
	int	best_target_val;

	i = 0;
	best_target_val = 2147483647;
	*target_idx = -1;
	while (i < a->size)
	{
		if (a->data[i] > b_val && a->data[i] < best_target_val)
		{
			best_target_val = a->data[i];
			*target_idx = i;
		}
		i++;
	}
	if (*target_idx == -1)
		*target_idx = find_min_index(a);
}

void	calculate_costs(t_stack *a, t_stack *b, int a_idx, t_cost *costs)
{
	int	b_idx;

	find_target_in_b(a, b, a_idx, &b_idx);
	if (a_idx <= a->size / 2)
		costs->a = a_idx;
	else
		costs->a = a_idx - a->size;
	if (b_idx <= b->size / 2)
		costs->b = b_idx;
	else
		costs->b = b_idx - b->size;
	if ((costs->a >= 0 && costs->b >= 0) || (costs->a < 0 && costs->b < 0))
	{
		if (abs_val(costs->a) > abs_val(costs->b))
			costs->total = abs_val(costs->a);
		else
			costs->total = abs_val(costs->b);
	}
	else
		costs->total = abs_val(costs->a) + abs_val(costs->b);
}

t_cost	calculate_swap_cost(t_stack *a, t_stack *b)
{
	t_cost	swap_cost;
	int		target_b_idx;

	swap_cost.a = 0;
	if (a->size < 2)
	{
		swap_cost.total = 2147483647;
		return (swap_cost);
	}
	find_target_in_b(a, b, 1, &target_b_idx);
	if (target_b_idx <= b->size / 2)
		swap_cost.b = target_b_idx;
	else
		swap_cost.b = target_b_idx - b->size;
	swap_cost.total = 1 + abs_val(swap_cost.b);
	return (swap_cost);
}
