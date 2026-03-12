/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:34:01 by whollebe          #+#    #+#             */
/*   Updated: 2025/11/18 15:08:23 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

//transforme le plus petit en 0, le 2eme plus petit en 1, ...
void	replace_data(t_stack *s, int *sorted, int *indexed)
{
	int	i;
	int	j;

	i = -1;
	while (++i < s->size)
	{
		j = -1;
		while (++j < s->size)
		{
			if (s->data[i] == sorted[j])
			{
				indexed[i] = j;
				break ;
			}
		}
	}
}

void	index_stack(t_stack *stack_a)
{
	int	*sorted_copy;
	int	*indexed_data;
	int	i;

	sorted_copy = malloc(sizeof(int) * stack_a->size);
	indexed_data = malloc(sizeof(int) * stack_a->size);
	if (!sorted_copy)
		return ;
	if (!indexed_data)
		return (free(sorted_copy));
	i = -1;
	while (++i < stack_a->size)
		sorted_copy[i] = stack_a->data[i];
	sort_tab(sorted_copy, stack_a->size);
	replace_data(stack_a, sorted_copy, indexed_data);
	free(stack_a->data);
	stack_a->data = indexed_data;
	free(sorted_copy);
}
