/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:57:02 by ele-moig          #+#    #+#             */
/*   Updated: 2026/03/12 11:57:37 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_signal;

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	g_signal = 0;
	data.exit_code = 0;
	data.env = NULL;
	data.cmd_nbr = 0;
	init_env(&data, env);
	setup_interactive_signals();
	while (1)
	{
		if (ft_minishell_handler(&data) == 1)
			break ;
	}
	free_all(&data, 1);
	return ((void)argc, (void)argv, data.exit_code);
}

int	ft_minishell_handler(t_data *data)
{
	init_data(data);
	data->line = readline(CYAN "Minishell$ " RESET);
	data->cmd_nbr++;
	if (ft_check_sig(data) == 1)
		return (1);
	ft_data_reassign(data);
	ft_expander(data);
	if (data->exit_code == 2)
		printf("Minishell: error: please close the quote\n");
	if (data->exit_code == 0)
		data->cmds = parser(data->token, data);
	if (data->exit_code == 0)
		assignment(data);
	if (data->token && data->cmds && data->exit_code == 0 && data->cmds->args)
		if (ft_executor(data) == 1)
			return (1);
	add_history(data->line);
	free_all(data, 0);
	return (0);
}
