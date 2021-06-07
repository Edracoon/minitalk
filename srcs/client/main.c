/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:41:32 by epfennig          #+#    #+#             */
/*   Updated: 2021/06/07 19:18:56 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit(0);
}

char	*convert_char_to_binary(char c)
{
	char	*tab;
	int		i;

	i = CHAR_BIT - 1;
	tab = malloc(sizeof(char) * (CHAR_BIT + 1));
	if (!(tab))
		ft_error("Error: Malloc failed");
	while (i >= 0)
	{
		tab[i] = (c % 2) + '0';
		c /= 2;
		i--;
	}
	tab[CHAR_BIT] = 0;
	return (tab);
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;
	int		j;
	char	*tab;

	i = -1;
	j = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][++i])
		{
			tab = convert_char_to_binary(av[2][i]);
			j = CHAR_BIT - 1;
			while (j >= 0)
			{
				printf("%c", tab[j]);
				if (tab[j] == '1')
				{
					kill(pid, SIGUSR2);
					usleep(1);
				}
				else if (tab[j] == '0')
				{
					kill(pid, SIGUSR1);
					usleep(1);
				}
				j--;
			}
			printf("\n");
			printf("av[2][%i] = %c\n", i, av[2][i]);
		}
	}
	else
		ft_error("Error: Argument\n");
	return (1);
}
