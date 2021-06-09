/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:41:32 by epfennig          #+#    #+#             */
/*   Updated: 2021/06/09 16:50:27 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

static int	g_sig = 0;

void	ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit(0);
}

void	glob_to_one(int i)
{
	(void)i;
	g_sig = 1;
}

void	send_charnull(int pid)
{
	int	j;

	j = CHAR_BIT - 1;
	while (j >= 0)
	{
		g_sig = 0;
		usleep(100);
		if (kill(pid, SIGUSR1) == -1)
			ft_error("Error: kill error\n");
		while (!g_sig)
			;
		j--;
	}
}

void	send_signal(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_sig = 0;
		usleep(100);
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error("Error: kill error\n");
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error("Error: kill error\n");
		}
		while (!g_sig)
			;
		i++;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;

	i = -1;
	g_sig = 0;
	signal(SIGUSR1, glob_to_one);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][++i])
			send_signal(av[2][i], pid);
		send_charnull(pid);
	}
	else
		ft_error("Error: Argument\n");
	return (1);
}
