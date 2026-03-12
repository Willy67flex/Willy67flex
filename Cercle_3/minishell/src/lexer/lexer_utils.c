/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:55:03 by ele-moig          #+#    #+#             */
/*   Updated: 2026/03/11 15:04:15 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_operator(char c)
{
	if (c == '>' || c == '<' || c == '|')
		return (1);
	return (0);
}

void	token_add_back(t_token **head, t_token *token)
{
	if (*head)
		ft_token_last(*head)->next_token = token;
	else
		*head = token;
}

t_token	*ft_token_last(t_token *token_head)
{
	t_token	*toreturn;

	if (!token_head)
		return (0);
	toreturn = token_head;
	while (toreturn->next_token)
		toreturn = toreturn->next_token;
	return (toreturn);
}

int	find_state(int c)
{
	if (c == '"')
		return (DQUOTE);
	else if (c == 39)
		return (SQUOTE);
	return (DEFAULT);
}

t_token	*ft_create_token(t_token *new_token, char *content, int type)
{
	if (!content)
	{
		free(new_token);
		return (NULL);
	}
	new_token->type = type;
	new_token->content = content;
	new_token->next_token = NULL;
	return (new_token);
}
