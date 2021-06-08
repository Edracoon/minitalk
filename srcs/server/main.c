/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:41:32 by epfennig          #+#    #+#             */
/*   Updated: 2021/06/08 17:42:46 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

int		g_i = 0;
char	*g_bin;

void	print_sig(int c)
{
	if (c == SIGUSR1)
	{
		g_bin[g_i] = '0';
	}
	else if (c == SIGUSR2)
	{
		g_bin[g_i] = '1';
	}
	g_i++;
}

int	main(void)
{
	pid_t	pid;
	char	c;
	int		i;

	c = 0;
	g_i = 0;
	g_bin = (char *)ft_calloc(CHAR_BIT + 1, sizeof(char));
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, print_sig);
	signal(SIGUSR2, print_sig);
	while (1)
	{
		if (g_bin[7] == '0' || g_bin[7] == '1')
		{
			i = 0;
			c = 0;
			while (i < 8)
			{
				c |= (g_bin[i] - '0')  << i;
				i++;
			}
			ft_putchar_fd(c, 1);
			ft_bzero((void *)g_bin, 8);
			g_i = 0;
		}
	}
	return (1);
}
