/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:04:40 by juson             #+#    #+#             */
/*   Updated: 2022/02/14 16:13:38 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	trans(int nbr, int len, char *base)
{
	if (nbr < len && nbr >= 0)
		write(1, &base[nbr], 1);
	else if (nbr >= len)
	{
		trans(nbr / len, len, base);
		nbr = nbr % len;
		write(1, &base[nbr], 1);
	}
	else if (nbr == -2147483648)
	{
		write(1, "-", 1);
		trans(-(nbr / len), len, base);
		write(1, &base[-(nbr % len)], 1);
	}
	else
	{
		write(1, "-", 1);
		trans(-nbr, len, base);
	}
}

int	base_ck(char *base, int *base_len)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base [j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	*base_len = i;
	while (i <= 1 || *base == '\0')
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;
	int	*base_len;

	len = 0;
	base_len = &len;
	if (base_ck(base, base_len) == 0)
		return ;
	trans(nbr, len, base);
}
