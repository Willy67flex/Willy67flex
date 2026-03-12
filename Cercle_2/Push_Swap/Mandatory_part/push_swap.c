/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:23:36 by whollebe          #+#    #+#             */
/*   Updated: 2025/11/20 10:39:55 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		*array;
	int		count;

	if (argc < 2)
		return (0);
	count = 0;
	array = handle_input(argc, argv, &count);
	if (!array)
		return (write(2, "Error\n", 6), 1);
	if (!init_stacks(&stack_a, &stack_b, array, count))
		return (free(array), 1);
	algo(&stack_a, &stack_b);
	return (free(stack_a.data), free(stack_b.data), free(array), 0);
}
