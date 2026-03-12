/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:44:09 by whollebe          #+#    #+#             */
/*   Updated: 2025/11/30 18:16:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct t_stack
{
	int	*data;
	int	size;
}	t_stack;

int		*build_array_whith_str(char *str, int *argc);
int		*built_array_with_n_args(char **argv, int argc);
int		*handle_input(int argc, char **argv, int *count);
int		check_args_are_valid(char **args, int argc);
int		check_args_are_int(long temp_long, int *result, int count, char **str);
int		check_doublons(int *str, int argc);
long	ft_atol(char *str);
void	free_split(char **str);
char	**ft_update_argv0(char **argv, int argc);
void	algo(t_stack *stack_a, t_stack *stack_b);
int		init_stacks(t_stack *a_ptr, t_stack *b_ptr, int *array, int size);
void	sa(t_stack *stack_a, int key);
void	pa(t_stack *stack_a, t_stack *stack_b, int key);
void	pb(t_stack *stack_a, t_stack *stack_b, int key);
void	sb(t_stack *stack_b, int key);
void	ss(t_stack *stack_a, t_stack *stack_b, int key);
void	ra(t_stack *stack_a, int key);
void	rb(t_stack *stack_b, int key);
void	rr(t_stack *stack_a, t_stack *stack_b, int key);
void	rra(t_stack *stack_a, int key);
void	rrb(t_stack *stack_b, int key);
void	rrr(t_stack *stack_a, t_stack *stack_b, int key);
void	args_lt_5(t_stack *stack_a, t_stack *stack_b);
void	two_args(t_stack *stack_a);
void	three_args(t_stack *stack_a);
void	four_args(t_stack *stack_a, t_stack *stack_b);
void	five_args(t_stack *stack_a, t_stack *stack_b);
int		find_lower_arg(t_stack *stack_a);
int		pos_lower_arg(t_stack *stack_a, int lower_arg);
void	put_lower_arg_pos_zero(t_stack *stack_a, int pos);
int		check_good_order(t_stack *stack_a);
void	n_args(t_stack *stack_a, t_stack *stack_b);
void	find_target_in_b(t_stack *a, t_stack *b, int a_idx, int *target_idx);
void	find_target_in_a(t_stack *a, int b_val, int *target_idx);
void	calculate_costs(t_stack *a, t_stack *b, int a_idx, t_cost *costs);
t_cost	calculate_swap_cost(t_stack *a, t_stack *b);
void	replace_data(t_stack *s, int *sorted, int *indexed);
void	index_stack(t_stack *stack_a);
void	execute_rotations(t_stack *a, t_stack *b, t_cost cost);
t_cost	find_cheapest_move(t_stack *a, t_stack *b, int *best_move_idx);
void	execute_cheapest_move(t_stack *a, t_stack *b);
void	move_back_to_a(t_stack *a, t_stack *b);
void	final_sort(t_stack *a);
int		find_max_index(t_stack *stack);
int		find_min_index(t_stack *stack);
int		abs_val(int n);
int		is_nearly_sorted(t_stack *stack);
void	sort_tab(int *tab, int size);

#endif // PUSH_SWAP_H
