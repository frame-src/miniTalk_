/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:06:59 by frmessin          #+#    #+#             */
/*   Updated: 2022/08/07 22:36:36 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_putnbr(int n)
{
	if (n == INT_MIN)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = n * (-1);
		}
		if (n < 10)
			ft_putchar(n + '0');
		else
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

void	ft_putstr(char *s)
{
	if (s != NULL)
		write(1, &s, ft_strlen(s));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
