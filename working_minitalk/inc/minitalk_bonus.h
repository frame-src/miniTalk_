/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 21:27:11 by frmessin          #+#    #+#             */
/*   Updated: 2022/08/07 22:56:13 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdbool.h>
# include <stddef.h>
# include <sys/types.h>
# include <limits.h>

typedef struct s_message
{
	int		char_value;
	int		bit_pos;
	pid_t	pid;
}			t_message;

void			ft_putstr(char *s);
void			ft_putchar(char c);
void			ft_putnbr(int n);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *str);

#endif