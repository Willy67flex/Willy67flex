/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:41:39 by ele-moig          #+#    #+#             */
/*   Updated: 2026/03/11 15:37:00 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_lexer(char *str, t_data *data)
{
	int		i;
	t_token	*token;
	t_token	*token_head;

	token_head = NULL;
	i = 0;
	if (!str || !str[i])
		return (NULL);
	while (is_space(str[i]) != 0)
		i++;
	while (str[i])
	{
		if (is_operator(str[i]))
			token = add_ope_token(str, i);
		else
			token = add_word_token(str, i);
		if (!token)
			return (data->token = token_head, exit(free_all(data, 1)), NULL);
		token_add_back(&token_head, token);
		i += ft_strlen(token->content);
		while (is_space(str[i]) != 0)
			i++;
	}
	return (token_head);
}

t_token	*add_ope_token(char *str, int index)
{
	t_token	*new_token;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	if (str[index] == '|')
		return (ft_create_token(new_token, ft_strdup("|"), TOKEN_PIPE));
	else if (str[index] == '>' && str[index + 1] == '>')
		return (ft_create_token(new_token, ft_strdup(">>"), TOKEN_APPEND));
	else if (str[index] == '>')
		return (ft_create_token(new_token, ft_strdup(">"), TOKEN_REDIR_OUT));
	else if (str[index] == '<' && str[index + 1] == '<')
		return (ft_create_token(new_token, ft_strdup("<<"), TKN_HERE));
	else if (str[index] == '<')
		return (ft_create_token(new_token, ft_strdup("<"), TOKEN_REDIR_IN));
	return (free(new_token), NULL);
}

t_token	*add_word_token(char *str, int index)
{
	t_token	*new_token;
	char	*content;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	content = word_content(str, index);
	return (ft_create_token(new_token, content, TOKEN_WORD));
}

void	skip_quotes(char *str, int *index, int state)
{
	(*index)++;
	if (state == DQUOTE)
	{
		while (str[*index] && str[*index] != '"')
			(*index)++;
	}
	else if (state == SQUOTE)
	{
		while (str[*index] && str[*index] != 39)
			(*index)++;
	}
}

char	*word_content(char *str, int index)
{
	int	start;
	int	state;

	start = index;
	while (str[index])
	{
		state = find_state(str[index]);
		if (state == DEFAULT)
		{
			if (is_operator(str[index]) || is_space(str[index]))
				break ;
		}
		else
			skip_quotes(str, &index, state);
		if (str[index] != '\0')
			index++;
	}
	return (ft_strndup(str + start, (index - start)));
}
