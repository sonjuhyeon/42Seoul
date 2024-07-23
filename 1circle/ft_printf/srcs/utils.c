/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:26:11 by juson             #+#    #+#             */
/*   Updated: 2022/05/10 18:26:11 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_n_base_len(long long n, int base)
{
	int	len;

	len = 1;
	while (n / base)
	{
		n = n / base;
		len++;
	}
	return (len);
}

int	ft_unsigned_n_base_len(long long n, int base)
{
	unsigned long long	m;
	int					len;

	m = (unsigned long long)n;
	len = 1;
	while (m / base)
	{
		m = m / base;
		len++;
	}
	return (len);
}

void	ft_putnbr_base(long long nb, char *base)
{
	int		base_len;
	char	c;

	base_len = ft_strlen(base);
	if (nb < base_len && nb >= 0)
	{
		c = base[nb];
		write(1, &c, 1);
	}
	else if (nb >= base_len)
	{
		ft_putnbr_base(nb / base_len, base);
		nb = nb % base_len;
		c = base[nb];
		write(1, &c, 1);
	}
	else
		ft_putnbr_base(-nb, base);
}

void	ft_unsigned_putnbr_base(unsigned long long nb, char *base)
{
	unsigned int	base_len;
	char			c;

	base_len = ft_strlen(base);
	if (nb < base_len)
	{
		c = base[nb];
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr_base(nb / base_len, base);
		nb = nb % base_len;
		c = base[nb];
		write(1, &c, 1);
	}
}
