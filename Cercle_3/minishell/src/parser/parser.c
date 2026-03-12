/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:40:20 by ele-moig          #+#    #+#             */
/*   Updated: 2026/03/11 15:33:11 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd_node	*parser(t_token *token_head, t_data *data)
{
	t_cmd_node	*cmd_head;
	t_token		*runner;

	runner = token_head;
	cmd_head = NULL;
	while (runner != NULL)
	{
		if (new_cmd_node(&cmd_head, &runner, data) == 1)
		{
			ft_free_cmd(cmd_head);
			data->exit_code = 1;
			return (NULL);
		}
	}
	return (cmd_head);
}

int	new_cmd_node(t_cmd_node **cmd_head, t_token **tkn_runner, t_data *data)
{
	t_cmd_node	*new_node;
	t_token		*cmd_start_tkn;
	int			count;

	count = 0;
	if ((*tkn_runner)->type == TOKEN_PIPE)
		return (ft_syntax_err("|"), 1);
	new_node = init_new_node();
	if (!new_node)
		return (1);
	cmd_start_tkn = *tkn_runner;
	count = count_args(*tkn_runner);
	if (handle_args(cmd_start_tkn, new_node, count, data) == 1
		|| handle_redir(*tkn_runner, new_node, data) == 1)
		return (1);
	while ((*tkn_runner) && (*tkn_runner)->type != TOKEN_PIPE)
		*tkn_runner = (*tkn_runner)->next_token;
	if ((*tkn_runner) && (*tkn_runner)->type == TOKEN_PIPE
		&& tkn_syntax_err(tkn_runner) == 1)
		return (1);
	if (ft_open_manager(new_node, data) != 0)
		return (ft_free_cmd(new_node), 1);
	cmd_add_back(cmd_head, new_node);
	data->cmd_node_nbr++;
	return (0);
}

int	tkn_syntax_err(t_token **tkn_runner)
{
	*tkn_runner = (*tkn_runner)->next_token;
	if (!(*tkn_runner))
	{
		ft_syntax_err("|");
		return (1);
	}
	return (0);
}

int	handle_args(t_token *runner, t_cmd_node *cmd_node, int count, t_data *data)
{
	int	i;

	i = 0;
	(void)data;
	cmd_node->args = ft_calloc((count + 1), (sizeof(char *)));
	if (!cmd_node->args)
		return (1);
	while (runner && runner->type != TOKEN_PIPE)
	{
		if (runner->type == TOKEN_WORD)
		{
			cmd_node->args[i] = ft_strdup(runner->content);
			if (!cmd_node->args[i])
				return (1);
			i++;
		}
		else if (runner->type >= TOKEN_REDIR_OUT && runner->type <= TKN_HERE)
		{
			if (runner->next_token)
				runner = runner->next_token;
		}
		runner = runner->next_token;
	}
	cmd_node->args[i] = NULL;
	return (0);
}

int	handle_redir(t_token *runner, t_cmd_node *cmd_node, t_data *data)
{
	t_redir	*new_redir;

	while (runner && runner->type != TOKEN_PIPE)
	{
		if (runner->type >= TOKEN_REDIR_OUT && runner->type <= TKN_HERE)
		{
			new_redir = ft_calloc(1, sizeof(t_redir));
			redir_init(new_redir, cmd_node, data, runner);
			if (runner->next_token && runner->next_token->type == TOKEN_WORD)
			{
				runner = runner->next_token;
				new_redir->path = ft_strdup(runner->content);
				if (!new_redir->path)
					redir_path_err(new_redir, data, cmd_node);
			}
			else
				return (parser_syntax_err(runner, new_redir));
			redir_add_back(&cmd_node->redirection, new_redir);
		}
		runner = runner->next_token;
	}
	return (0);
}
