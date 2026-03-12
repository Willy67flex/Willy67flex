/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 10:04:51 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/11 15:36:13 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	free_all(t_data *data, int flag)
{
	int	exit_code;

	exit_code = data->final_exit_code;
	free(data->line);
	if (flag == 1)
	{
		free_env(data);
		rl_clear_history();
	}
	ft_free_tokens(data->token);
	ft_free_cmd(data->cmds);
	if (data->tab != NULL)
		ft_free_tab(data->tab);
	if (data->path != NULL)
		free(data->path);
	return (exit_code);
}
