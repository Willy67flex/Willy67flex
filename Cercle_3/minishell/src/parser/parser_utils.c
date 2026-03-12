/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:16:58 by ele-moig          #+#    #+#             */
/*   Updated: 2026/03/11 14:25:31 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_add_back(t_cmd_node **head, t_cmd_node *cmd_node)
{
	if (*head)
		ft_cmd_last(*head)->next_cmd = cmd_node;
	else
		*head = cmd_node;
}

t_cmd_node	*ft_cmd_last(t_cmd_node *cmd_head)
{
	t_cmd_node	*toreturn;

	if (!cmd_head)
		return (0);
	toreturn = cmd_head;
	while (toreturn->next_cmd)
		toreturn = toreturn->next_cmd;
	return (toreturn);
}

void	redir_add_back(t_redir **head, t_redir *redir)
{
	if (*head)
		ft_redir_last(*head)->next_redir = redir;
	else
		*head = redir;
}

t_redir	*ft_redir_last(t_redir *redir_head)
{
	t_redir	*toreturn;

	if (!redir_head)
		return (0);
	toreturn = redir_head;
	while (toreturn->next_redir)
		toreturn = toreturn->next_redir;
	return (toreturn);
}

t_cmd_node	*init_new_node(void)
{
	t_cmd_node	*new_node;

	new_node = calloc(1, sizeof(t_cmd_node));
	if (!new_node)
		return (NULL);
	new_node->fd_in = -2;
	new_node->fd_out = -2;
	return (new_node);
}
