/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 09:49:45 by whollebe          #+#    #+#             */
/*   Updated: 2025/11/28 09:45:28 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile int	g_ack = 0;

void	ft_error_and_exit(char *msg)
{
	ft_printf("Error: %s\n", msg);
	exit(EXIT_FAILURE);
}

void	client_ack_handler(int sig)
{
	if (sig == SIGUSR1)
		g_ack = 1;
	else if (sig == SIGUSR2)
	{
		ft_printf("Message send!\n");
		exit(EXIT_SUCCESS);
	}
}

void	send_bit(int server_pid, char c)
{
	int	bit_index;
	int	timeout_count;

	timeout_count = 0;
	bit_index = 8;
	while (--bit_index >= 0)
	{
		g_ack = 0;
		if ((c >> bit_index) & 1)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				ft_error_and_exit("Error: Failed to send SIGUSR1.\n");
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				ft_error_and_exit("Error: Failed to send SIGUSR2.\n");
		}
		while (!g_ack)
		{
			usleep(100);
			if (timeout_count++ > 5000)
				ft_error_and_exit("Error: timeout. Lost bit.\n");
		}
	}
}

int	main(int argc, char **argv)
{
	int					server_pid;
	char				*message;
	struct sigaction	sa_ack;
	int					i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Usage: ./client <SERVER_PID> <MESSAGE>\n");
		return (1);
	}
	sa_ack.sa_handler = client_ack_handler;
	sigemptyset(&sa_ack.sa_mask);
	sa_ack.sa_flags = 0;
	sigaction(SIGUSR1, &sa_ack, NULL);
	sigaction(SIGUSR2, &sa_ack, NULL);
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	while (message[i] != '\0')
	{
		send_bit(server_pid, message[i]);
		i++;
	}
	send_bit(server_pid, '\0');
	return (0);
}
