/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_execve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:05:33 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/11 14:30:33 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_key_value(t_env *n)
{
	int		i;
	int		j;
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(n->key) + ft_strlen(n->value) + 2));
	if (!str)
		return (NULL);
	i = -1;
	while (n->key[++i])
		str[i] = n->key[i];
	str[i] = '=';
	i++;
	j = 0;
	while (n->value[j])
	{
		str[i] = n->value[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	print_tab(char **tab, int key)
{
	int	i;

	i = -1;
	while (tab[++i])
		if (key == 1)
			printf("tab[%d] = \"%s\"\n", i, tab[i]);
	return (i);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	check_child_sig(int wstatus, int *flag_sig)
{
	if (WIFSIGNALED(wstatus) && *flag_sig == 0)
	{
		if (WTERMSIG(wstatus) == SIGQUIT)
			write(2, "Quit (core dumped)\n", 19);
		else if (WTERMSIG(wstatus) == SIGINT)
			write(1, "\n", 1);
		(*flag_sig)++;
	}
}

//waiting all children and getting signal
void	wait_children(pid_t last_pid, t_data *data, int cmd_nbr)
{
	int		i;
	int		flag_sig;
	int		wstat;
	pid_t	tmp_pid;

	i = 0;
	flag_sig = 0;
	while (i < cmd_nbr)
	{
		tmp_pid = waitpid(-1, &wstat, 0);
		if (tmp_pid == -1 && errno == EINTR)
			continue ;
		else if (tmp_pid == -1)
			break ;
		check_child_sig(wstat, &flag_sig);
		if (tmp_pid == last_pid && WIFEXITED(wstat))
			data->exit_code = WEXITSTATUS(wstat);
		else if (tmp_pid == last_pid && WIFSIGNALED(wstat))
			data->exit_code = 128 + WTERMSIG(wstat);
		i++;
	}
}
