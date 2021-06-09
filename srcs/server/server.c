/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:41:32 by epfennig          #+#    #+#             */
/*   Updated: 2021/06/09 17:30:51 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	translate_to_char(int b)
{
	static int				i = 0;
	static unsigned char	c = 0;

	c |= (b) << i++;
	if (i > 7)
	{
		if (c == '\0')
		{
			ft_putchar_fd('\n', 1);
			ft_putchar_fd(c, 1);
		}
		else
			ft_putchar_fd(c, 1);
		i = 0;
		c = 0;
	}
}

void	sig_client(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		translate_to_char(0);
	else if (sig == SIGUSR2)
		translate_to_char(1);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sigact;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = sig_client;
	sigemptyset(&sigact.sa_mask);
	sigaddset(&sigact.sa_mask, SIGUSR1);
	sigaddset(&sigact.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
		pause();
	return (1);
}
