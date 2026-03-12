/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:50:19 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/10 18:11:15 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	update_existing_env(t_env *node, char *value, int flag, int nb)
{
	if (nb == 0)
		node->flag = 0;
	if (value == NULL)
		return (1);
	free(node->value);
	node->value = value;
	return (1);
	(void)flag;
}

t_env	*get_env_node(t_env *head, char *key)
{
	t_env	*runner;

	runner = head;
	while (runner != NULL)
	{
		if (ft_strcmp(runner->key, key) == 0)
			return (runner);
		runner = runner->next_env;
	}
	return (NULL);
}

int	ft_export(t_data *data, char *s, int nb)
{
	char	*key;
	char	*value;
	int		flag;
	t_env	*node;

	if (s == NULL)
		return (print_sort_export(data), 0);
	extract_key_value(s, &key, &value);
	flag = check_is_a_valide_key(key, s);
	if (flag == 1)
	{
		data->exit_code = print_export_error(s, key, value, nb);
		return (1);
	}
	if (flag == 2)
		key = strdup_check_key_return_2(key);
	node = get_env_node(data->env, key);
	if (node != NULL)
		if (update_existing_env(node, value, flag, nb))
			return (free(key), 0);
	add_env_node(data, key, value, nb);
	return (0);
}

void	apply_assignments(t_data *data, t_cmd_node *runner, int is_child)
{
	int	i;

	if (!runner->assignment)
		return ;
	i = 0;
	while (runner->assignment[i])
	{
		if (is_child == 1)
			ft_export(data, runner->assignment[i], 0);
		else
			ft_export(data, runner->assignment[i], 1);
		i++;
	}
}

void	execute_builtin_export(t_data *data, t_cmd_node *runner)
{
	int	i;

	if (!runner->args || !runner->args[0])
		return ;
	if (runner->args[1] == NULL)
	{
		ft_export(data, NULL, 0);
		return ;
	}
	i = 1;
	while (runner->args[i])
	{
		ft_export(data, runner->args[i], 0);
		i++;
	}
}
