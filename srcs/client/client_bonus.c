/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:20:54 by epfennig          #+#    #+#             */
/*   Updated: 2021/06/09 15:21:12 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

static	int	g_sig = 0;

void	ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit(0);
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

void	send_signal(char *tab, int pid)
{
	int	i;

	i = CHAR_BIT - 1;
	while (i >= 0)
	{
		g_sig = 0;
		usleep(100);
		if (tab[i] == '1')
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error("Error: kill error\n");
		}
		else if (tab[i] == '0')
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error("Error: kill error\n");
		}
		while (!g_sig)
			;
		i--;
	}
}

void	glob_to_one()
{
	g_sig = 1;
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;
	int		j;
	char	*tab;

	i = -1;
	j = 0;
	g_sig = 0;
	signal(SIGUSR1, glob_to_one);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][++i])
		{
			tab = convert_char_to_binary(av[2][i]);
			send_signal(tab, pid);
			free(tab);
		}
		send_charnull(pid);
		write(1, "Server feedback: Message received\n", 35);
	}
	else
		ft_error("Error: Argument\n");
	return (1);
}