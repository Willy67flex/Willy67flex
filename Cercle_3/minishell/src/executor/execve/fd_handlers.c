/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_handlers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:18:53 by ele-moig          #+#    #+#             */
/*   Updated: 2026/03/11 14:03:17 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_fd_handler(t_cmd_node *runner, pid_t *prev_fd, int *pipe_fd)
{
	if (runner->fd_in != -2)
		dup2(runner->fd_in, 0);
	else if (*prev_fd != -2)
		dup2(*prev_fd, 0);
	if (runner->fd_out != -2)
		dup2(runner->fd_out, 1);
	else
		dup2(pipe_fd[1], 1);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	if (*prev_fd != -2)
		close(*prev_fd);
}

void	parent_fd_handler(int *pipe_fd, pid_t *prev_fd)
{
	if (*prev_fd != -2)
		close(*prev_fd);
	*prev_fd = pipe_fd[0];
	close(pipe_fd[1]);
}
