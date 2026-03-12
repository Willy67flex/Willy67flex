/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commande_stack_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:53:49 by whollebe          #+#    #+#             */
/*   Updated: 2025/11/18 18:46:29 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a, int key)
{
	int	tps;

	if (stack_a->size < 2)
		return ;
	tps = stack_a->data[1];
	stack_a->data[1] = stack_a->data[0];
	stack_a->data[0] = tps;
	if (key == 1)
		ft_printf("sa\n");
}

void	pa(t_stack *stack_a, t_stack *stack_b, int key)
{
	int	i;
	int	value_to_push;

	if (stack_b->size == 0)
		return ;
	value_to_push = stack_b->data[0];
	i = stack_a->size;
	while (i > 0)
	{
		stack_a->data[i] = stack_a->data[i - 1];
		i--;
	}
	stack_a->data[0] = value_to_push;
	stack_a->size++;
	i = 0;
	while (i < stack_b->size - 1)
	{
		stack_b->data[i] = stack_b->data[i + 1];
		i++;
	}
	stack_b->size--;
	if (key == 1)
		ft_printf("pa\n");
}

void	ra(t_stack *stack_a, int key)
{
	int	value_to_move;
	int	i;

	if (stack_a->size < 2)
		return ;
	value_to_move = stack_a->data[0];
	i = 0;
	while (i < stack_a->size - 1)
	{
		stack_a->data[i] = stack_a->data[i + 1];
		i++;
	}
	stack_a->data[stack_a->size - 1] = value_to_move;
	if (key == 1)
		ft_printf("ra\n");
}

void	rra(t_stack *stack_a, int key)
{
	int	value_to_move;
	int	i;

	if (stack_a->size < 2)
		return ;
	i = stack_a->size - 1;
	value_to_move = stack_a->data[i];
	while (i > 0)
	{
		stack_a->data[i] = stack_a->data[i - 1];
		i--;
	}
	stack_a->data[0] = value_to_move;
	if (key == 1)
		ft_printf("rra\n");
}
