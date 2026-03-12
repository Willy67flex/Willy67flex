/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 11:49:05 by ele-moig          #+#    #+#             */
/*   Updated: 2026/03/11 13:59:41 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_heredoc_err(int line_nbr, char *delim)
{
	ft_putstr_fd("Minishell: warning: here-document at line ", 2);
	ft_putnbr_fd(line_nbr, 2);
	ft_putstr_fd(" delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(delim, 2);
	ft_putstr_fd("')\n", 2);
}

int	check_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

int	ft_heredoc_wr(int tmp_fd, t_data *data, char *delim)
{
	char	*str;

	while (1)
	{
		str = readline(CYAN ">" RESET);
		if (!str)
		{
			ft_heredoc_err(data->cmd_nbr, delim);
			break ;
		}
		if (ft_strcmp(str, delim) == 0)
		{
			free(str);
			break ;
		}
		if (check_dollar(str) == 1)
			ft_heredoc_expander(&str, data);
		write(tmp_fd, str, ft_strlen(str));
		write(tmp_fd, "\n", 1);
		free(str);
	}
	return (0);
}

void	del_dollar(char **str, int start, t_data *data)
{
	int		i;
	int		j;
	char	*new_str;
	int		len_key;

	len_key = check_key(&(*str)[start + 1]);
	new_str = malloc(sizeof(char) * (ft_strlen(*str) - len_key));
	if (!new_str)
		exit(free_all(data, 1));
	i = 0;
	while (i < start)
	{
		new_str[i] = (*str)[i];
		i++;
	}
	j = start + len_key + 1;
	while ((*str)[j])
		new_str[i++] = (*str)[j++];
	new_str[i] = '\0';
	free(*str);
	*str = new_str;
}

void	ft_heredoc_expander(char **str, t_data *data)
{
	int		i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '$')
		{
			if (process_dollar(str, &i, data) == 1)
				del_dollar(str, i, data);
		}
		else
			i++;
	}
}
