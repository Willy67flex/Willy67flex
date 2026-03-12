/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 09:49:50 by whollebe          #+#    #+#             */
/*   Updated: 2025/11/28 09:49:13 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_finished(int client_pid)
{
	ft_printf("\n");
	if (kill(client_pid, SIGUSR2) == -1)
		ft_printf("Warning: Failed to send final signal to client.\n");
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static int	result = 0;
	static int	power = 7;
	static int	client_pid = 0;

	if (info->si_pid != 0)
		client_pid = info->si_pid;
	if (sig == SIGUSR1)
		result |= (1 << power);
	if (--power < 0)
	{
		if (result == 0)
		{
			if (client_pid != 0)
				ft_send_finished(client_pid);
		}
		else
			ft_putchar_fd(result, 1);
		result = 0;
		power = 7;
	}
	if (power >= 0 && client_pid != 0)
		kill(client_pid, SIGUSR1);
	(void)context;
}

void	print_pid(int pid)
{
	ft_printf("/********************************************/\n");
	ft_printf("/*                                          */\n");
	ft_printf("/*                  Server                  */\n");
	ft_printf("/*               pid= %d               */\n", pid);
	ft_printf("/*                                          */\n");
	ft_printf("/********************************************/\n\n");
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	print_pid(pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
