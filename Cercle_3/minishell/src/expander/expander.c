/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:43:45 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/12 12:02:06 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*update_args(char *str, t_data *data, int *flag)
{
	int		i;
	char	*new_str;

	new_str = ft_strdup(str);
	if (!new_str)
		exit(free_all(data, 1));
	i = 0;
	while (new_str && new_str[i])
	{
		if (ft_args_case(&new_str, &i, data, flag) != 0)
			return (NULL);
	}
	return (new_str);
}

int	ft_args_case(char **new_str, int *i, t_data *data, int *flag)
{
	if ((*new_str)[*i] == 39)
	{
		if (process_squotes(new_str, i, data))
			return (free(*new_str), *flag = 1, 1);
	}
	else if ((*new_str)[*i] == '"')
	{
		if (process_dquotes(new_str, i, data))
			return (free(*new_str), *flag = 1, 1);
	}
	else if ((*new_str)[*i] == '$')
	{
		if (process_dollar(new_str, i, data) == 1)
			return (free(*new_str), *flag = 2, 1);
	}
	else
		(*i)++;
	return (0);
}

char	*verif_args(char *str, t_data *data)
{
	char	*new_str;
	int		flag;

	flag = 0;
	if (scan_arg(str) == 1)
	{
		new_str = update_args(str, data, &flag);
		if (new_str == NULL && flag == 1)
			return (data->exit_code = 2, NULL);
		if (new_str == NULL && flag == 2)
			return (data->exit_code = 0, NULL);
		free(str);
		return (new_str);
	}
	return (str);
}

void	del_token_node(t_token **token, t_token **prev,
			t_token **next_save, t_data *data)
{
	if ((*token)->content)
		free((*token)->content);
	free(*token);
	if (*prev == NULL)
		data->token = *next_save;
	else
		(*prev)->next_token = *next_save;
	*token = *next_save;
}

void	ft_expander(t_data *data)
{
	t_token	*token;
	t_token	*prev;
	t_token	*next;
	char	*temp;

	token = data->token;
	prev = NULL;
	while (token)
	{
		next = token->next_token;
		if (token->type == TOKEN_WORD)
		{
			temp = verif_args(token->content, data);
			if (data->exit_code == 0 && temp == NULL)
			{
				del_token_node(&token, &prev, &next, data);
				continue ;
			}
			if (data->exit_code == 2)
				return ;
			token->content = temp;
		}
		prev = token;
		token = next;
	}
}
