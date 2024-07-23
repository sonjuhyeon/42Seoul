/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:55:04 by juson             #+#    #+#             */
/*   Updated: 2022/02/22 10:44:07 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*make_newrange(long long rng, long long n_min)
{
	int			*n_range;
	long long	i;

	i = 0;
	n_range = (int *)malloc(sizeof(int) * rng);
	if (!n_range)
	{
		n_range = 0;
		return (n_range);
	}
	while (i < rng)
		n_range[i++] = n_min++;
	return (n_range);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	long long	n_min;
	long long	n_max;
	long long	rng;

	n_min = (long long)min;
	n_max = (long long)max;
	rng = n_max - n_min;
	if (rng <= 0)
	{
		*range = 0;
		return (0);
	}
	*range = make_newrange(rng, n_min);
	if (!*range)
		return (-1);
	return (rng);
}
