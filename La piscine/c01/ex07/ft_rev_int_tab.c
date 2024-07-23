/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:39:38 by juson             #+#    #+#             */
/*   Updated: 2022/02/08 16:21:47 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	rev_time;
	int	i;
	int	rev_i;
	int	tmp;

	rev_time = size / 2;
	i = 0;
	while (i < rev_time)
	{
		tmp = tab[i];
		rev_i = size - 1 - i;
		tab[i] = tab[rev_i];
		tab[rev_i] = tmp;
		i++;
	}
}
