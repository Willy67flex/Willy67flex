/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:54:15 by ele-moig          #+#    #+#             */
/*   Updated: 2026/03/12 11:55:07 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_data_reassign(t_data *data)
{
	exit_code(data, data->exit_code);
	data->final_exit_code = data->exit_code;
	data->exit_code = 0;
	data->cmd_node_nbr = 0;
	data->token = ft_lexer(data->line, data);
}

int	ft_check_sig(t_data *data)
{
	if (g_signal == SIGINT)
	{
		data->exit_code = 130;
		g_signal = 0;
	}
	if (!data->line)
	{
		printf("exit\n");
		return (1);
	}
	return (0);
}

void	exit_code(t_data *data, int code)
{
	t_env	*node;

	node = data->env;
	data->exit_code = code;
	node = get_env_node(node, "?");
	free(node->value);
	node->value = ft_itoa(code);
}

void	init_data(t_data *data)
{
	data->cmds = NULL;
	data->token = NULL;
	data->tab = NULL;
	data->path = NULL;
}
