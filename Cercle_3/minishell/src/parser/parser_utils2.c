/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:25:03 by ele-moig          #+#    #+#             */
/*   Updated: 2026/03/11 15:33:20 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_syntax_err(char *str)
{
	ft_putstr_fd("Minishell: syntax error near unexpected token `", 2);
	if (!str)
		ft_putstr_fd("new line", 2);
	else
		ft_putstr_fd(str, 2);
	ft_putstr_fd("'\n", 2);
}

int	count_args(t_token *tmp_tkn)
{
	int	count;

	count = 0;
	while (tmp_tkn && tmp_tkn->type != TOKEN_PIPE)
	{
		if (tmp_tkn->type == TOKEN_WORD)
			count++;
		else if (tmp_tkn->type >= TOKEN_REDIR_OUT
			&& tmp_tkn->type <= TKN_HERE)
		{
			if (tmp_tkn->next_token)
				tmp_tkn = tmp_tkn->next_token;
		}
		tmp_tkn = tmp_tkn->next_token;
	}
	return (count);
}

int	parser_syntax_err(t_token *tkn_runner, t_redir *new_redir)
{
	if (!tkn_runner->next_token)
		ft_syntax_err("new line");
	else
		ft_syntax_err(tkn_runner->next_token->content);
	free(new_redir);
	return (1);
}

void	redir_init(t_redir *new_redir, t_cmd_node *cmd_node,
	t_data *data, t_token *runner)
{
	if (!new_redir)
	{
		ft_free_cmd(cmd_node);
		exit(free_all(data, 1));
	}
	new_redir->operator = runner->type;
	new_redir->next_redir = NULL;
}

void	redir_path_err(t_redir *new_redir, t_data *data, t_cmd_node *cmd_node)
{
	free(new_redir);
	ft_free_cmd(cmd_node);
	exit(free_all(data, 1));
}
