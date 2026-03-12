/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 11:25:15 by ele-moig          #+#    #+#             */
/*   Updated: 2026/03/11 14:24:05 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_cmd(t_cmd_node	*cmd_node)
{
	t_cmd_node	*tmp;

	while (cmd_node != NULL)
	{
		tmp = cmd_node;
		cmd_node = cmd_node->next_cmd;
		if (tmp->fd_in != -2)
			close(tmp->fd_in);
		if (tmp->fd_out != -2)
			close(tmp->fd_out);
		if (tmp->assignment != NULL)
			ft_free_tab(tmp->assignment);
		if (tmp->args != NULL)
			ft_free_tab(tmp->args);
		if (tmp->redirection != NULL)
			ft_free_redir(tmp->redirection);
		free(tmp);
	}
	return ;
}

void	ft_free_redir(t_redir *lst)
{
	t_redir	*tmp;

	while (lst != NULL)
	{
		tmp = lst;
		lst = lst->next_redir;
		free(tmp->path);
		free(tmp);
	}
	return ;
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return ;
}

void	ft_free_tokens(t_token *lst)
{
	t_token	*tmp;

	while (lst)
	{
		tmp = lst->next_token;
		free(lst->content);
		free(lst);
		lst = tmp;
	}
}
