/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:07:05 by frmessin          #+#    #+#             */
/*   Updated: 2022/08/07 23:28:00 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static int	ft_atoi(const char *str)
{
	int		x;
	int		i;
	int		sign;

	x = 0;
	i = 0;
	sign = 1;
	while (str[i] == 9 || str[i] == 32 || str[i] == 10 || str[i] == 11
		|| str[i] == 12 || str[i] == 13)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		x = x * 10 + str[i++] - '0';
	return (x * sign);
}

static bool	check_input(int argument, char **message)
{
	if (argument != 3)
		return (false);
	if (ft_atoi (message[1]) < 0)
		return (false);
	return (true);
}

void	send_message(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i & 1) == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		usleep(600);
	}
}

int	main(int argc, char *argv[])
{
	if (!check_input(argc, argv))
		return (0);
	while (*(argv[2]))
		send_message(ft_atoi(argv[1]), *(argv[2]++));
	send_message(ft_atoi(argv[1]), *argv[2]);
	pause();
	return (0);
}
