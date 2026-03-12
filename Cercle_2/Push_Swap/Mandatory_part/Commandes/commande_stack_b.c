/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commande_stack_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:53:55 by whollebe          #+#    #+#             */
/*   Updated: 2025/11/18 18:46:42 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *stack_b, int key)
{
	int	tps;

	if (stack_b->size < 2)
		return ;
	tps = stack_b->data[1];
	stack_b->data[1] = stack_b->data[0];
	stack_b->data[0] = tps;
	if (key == 1)
		ft_printf("sb\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b, int key)
{
	int	i;
	int	value_to_push;

	if (stack_a->size == 0)
		return ;
	value_to_push = stack_a->data[0];
	i = stack_b->size;
	while (i > 0)
	{
		stack_b->data[i] = stack_b->data[i - 1];
		i--;
	}
	stack_b->data[0] = value_to_push;
	stack_b->size++;
	i = 0;
	while (i < stack_a->size - 1)
	{
		stack_a->data[i] = stack_a->data[i + 1];
		i++;
	}
	stack_a->size--;
	if (key == 1)
		ft_printf("pb\n");
}

void	rb(t_stack *stack_b, int key)
{
	int	value_to_move;
	int	i;

	if (stack_b->size < 2)
		return ;
	value_to_move = stack_b->data[0];
	i = 0;
	while (i < stack_b->size - 1)
	{
		stack_b->data[i] = stack_b->data[i + 1];
		i++;
	}
	stack_b->data[stack_b->size - 1] = value_to_move;
	if (key == 1)
		ft_printf("rb\n");
}

void	rrb(t_stack *stack_b, int key)
{
	int	value_to_move;
	int	i;

	if (stack_b->size < 2)
		return ;
	i = stack_b->size - 1;
	value_to_move = stack_b->data[i];
	while (i > 0)
	{
		stack_b->data[i] = stack_b->data[i - 1];
		i--;
	}
	stack_b->data[0] = value_to_move;
	if (key == 1)
		ft_printf("rrb\n");
}
