/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:27:28 by juson             #+#    #+#             */
/*   Updated: 2022/02/22 16:36:03 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	*val;
	int	i;

	i = 0;
	val = (int *)malloc(sizeof(int) * length);
	while (i < length)
	{
		val[i] = f(tab[i]);
		i++;
	}
	return (val);
}
