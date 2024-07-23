/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:15:42 by juson             #+#    #+#             */
/*   Updated: 2022/03/30 16:16:12 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	num_len(int n)
{
	int			len;
	long long	m;

	len = 1;
	m = n;
	if (n < 0)
		m = -n;
	else
		m = n;
	while (m / 10)
	{
		m = m / 10;
		len++;
	}
	if (n < 0)
		return (++len);
	else
		return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			n_len;
	long long	m;

	n_len = num_len(n);
	str = (char *)malloc(n_len + 1);
	if (str == 0)
		return (0);
	m = n;
	if (m < 0)
		m = -m;
	str[n_len] = '\0';
	while (0 < n_len)
	{
		str[n_len - 1] = m % 10 + '0';
		m /= 10;
		n_len--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
