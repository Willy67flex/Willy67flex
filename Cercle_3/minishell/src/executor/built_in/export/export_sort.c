/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:26:22 by whollebe          #+#    #+#             */
/*   Updated: 2026/02/27 11:17:38 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reset_print_setting(t_env *runner)
{
	while (runner)
	{
		runner->print = 0;
		runner = runner->next_env;
	}
}

t_env	*find_smaller(t_env *smaller, t_env *runner)
{
	while (runner)
	{
		if (runner->print == 0 && runner->flag == 0)
		{
			if (smaller == NULL)
				smaller = runner;
			else if (ft_strcmp(runner->key, smaller->key) < 0)
				smaller = runner;
		}
		runner = runner->next_env;
	}
	return (smaller);
}

void	print_sort_export(t_data *data)
{
	int		count;
	int		i;
	t_env	*runner;
	t_env	*smaller;

	count = size_env(data);
	i = 0;
	while (i < count)
	{
		runner = data->env;
		smaller = NULL;
		smaller = find_smaller(smaller, runner);
		if (smaller)
		{
			if (smaller->value)
				printf("export %s=\"%s\"\n", smaller->key, smaller->value);
			else
				printf("export %s\n", smaller->key);
			smaller->print = 1;
		}
		i++;
	}
	runner = data->env;
	reset_print_setting(runner);
}
