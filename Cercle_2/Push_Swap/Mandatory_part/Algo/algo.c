/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:16:00 by whollebe          #+#    #+#             */
/*   Updated: 2025/11/30 18:17:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size < 2)
		return ;
	if (stack_a->size <= 5)
		args_lt_5(stack_a, stack_b);
	if (stack_a->size > 5)
		n_args(stack_a, stack_b);
}
