/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:15:44 by whollebe          #+#    #+#             */
/*   Updated: 2025/11/20 10:40:23 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmp_stack_with_tab_sort(t_stack *stack_a, t_stack *stack_b, int *array)
{
	int	i;

	i = 0;
	sort_tab(array, stack_a->size);
	while (i < stack_a->size)
	{
		if (stack_a->data[i] != array[i])
		{
			ft_printf("KO\n");
			return ;
		}
		i++;
	}
	if (stack_b->size != 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}

int	run_commande(char *cmd, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(cmd, "sa\n", 3) == 0)
		sa(stack_a, 0);
	else if (ft_strncmp(cmd, "sb\n", 3) == 0)
		sb(stack_b, 0);
	else if (ft_strncmp(cmd, "ss\n", 3) == 0)
		ss(stack_a, stack_b, 0);
	else if (ft_strncmp(cmd, "pa\n", 3) == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strncmp(cmd, "pb\n", 3) == 0)
		pb(stack_a, stack_b, 0);
	else if (ft_strncmp(cmd, "ra\n", 3) == 0)
		ra(stack_a, 0);
	else if (ft_strncmp(cmd, "rb\n", 3) == 0)
		rb(stack_b, 0);
	else if (ft_strncmp(cmd, "rr\n", 3) == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strncmp(cmd, "rra\n", 4) == 0)
		rra(stack_a, 0);
	else if (ft_strncmp(cmd, "rrb\n", 4) == 0)
		rrb(stack_b, 0);
	else if (ft_strncmp(cmd, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b, 0);
	else
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		*array;
	int		count;
	char	*commande;

	if (argc < 2)
		return (0);
	count = 0;
	array = handle_input(argc, argv, &count);
	if (!array)
		return (write(2, "Error\n", 6), 1);
	if (!init_stacks(&stack_a, &stack_b, array, count))
		return (free(array), 1);
	commande = get_next_line(0);
	while (commande)
	{
		if (run_commande(commande, &stack_a, &stack_b) == 1)
			return (free(commande), free(array), free(stack_a.data),
				free(stack_b.data), ft_printf("Error\n"), 1);
		free(commande);
		commande = get_next_line(0);
	}
	cmp_stack_with_tab_sort(&stack_a, &stack_b, array);
	return (free(stack_a.data), free(stack_b.data), free(array), 0);
}
