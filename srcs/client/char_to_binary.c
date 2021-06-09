/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:19:46 by epfennig          #+#    #+#             */
/*   Updated: 2021/06/09 15:20:05 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

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