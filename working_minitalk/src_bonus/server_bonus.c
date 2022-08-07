/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 20:45:20 by frmessin          #+#    #+#             */
/*   Updated: 2022/08/07 23:28:57 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	send_message_back(int pid)
{
	kill(pid, SIGUSR1);
}

static void	var_init(t_message *var)
{
	var->char_value = 0;
	var->bit_pos = 0;
}

void	handler(int sign_val, siginfo_t *info, void *context)
{
	static t_message	message;

	if(sign_val < 0)
		exit (0);
	context = NULL;
	if (message.pid != info->si_pid)
		var_init(&message);
	message.pid = info->si_pid;
	message.char_value = ((message.char_value) << 1) | (sign_val & 1);
	message.bit_pos++;
	if (message.bit_pos == 8)
	{
		write(1, &(message.char_value), 1);
		if (message.char_value == 0)
		{
			write(1, "\n", 1);
			send_message_back(message.pid);
		}
		var_init (&message);
	}
	return ;
}

int	main(void)
{
	struct sigaction	s_signal;
	pid_t				pid;

	sigemptyset (&(s_signal.sa_mask));
	s_signal.sa_sigaction = &handler;
	s_signal.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_signal, NULL);
	sigaction(SIGUSR2, &s_signal, NULL);
	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
		pause ();
	return (0);
}
