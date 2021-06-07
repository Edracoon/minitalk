/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:41:32 by epfennig          #+#    #+#             */
/*   Updated: 2021/06/07 19:18:36 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	print_sig(int c)
{
	if (c == SIGUSR1)
		ft_putchar_fd('0', 1);
	if (c == SIGUSR2)
		ft_putchar_fd('1', 1);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, print_sig);
	signal(SIGUSR2, print_sig);
	while (1)
	{
		;
	}
	return (1);
}
