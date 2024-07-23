/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:51:42 by juson             #+#    #+#             */
/*   Updated: 2022/02/22 10:39:53 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int			*nbrs;
	long long	i;
	long long	rng;
	long long	n_min;
	long long	n_max;

	n_min = (long long)min;
	n_max = (long long)max;
	rng = n_max - n_min;
	if (rng <= 0)
		return (0);
	nbrs = malloc(sizeof(int) * rng);
	if (!nbrs)
		return (0);
	i = 0;
	while (i < rng)
		nbrs[i++] = min++;
	return (nbrs);
}
