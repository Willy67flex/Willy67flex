/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:53:46 by whollebe          #+#    #+#             */
/*   Updated: 2026/02/27 14:23:29 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_cmd_node *runner)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (runner->args[1] && ft_strcmp(runner->args[1], "-n") == 0)
	{
		flag = 1;
		i++;
	}
	while (runner->args[i])
	{
		if (runner->args[i][0] == '\0')
		{
			i++;
			continue ;
		}
		if (runner->args[i + 1] == NULL)
			printf("%s", runner->args[i]);
		else
			printf("%s ", runner->args[i]);
		i++;
	}
	if (flag == 0)
		printf("\n");
}
