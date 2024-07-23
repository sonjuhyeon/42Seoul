/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:05:21 by juson             #+#    #+#             */
/*   Updated: 2022/02/09 11:05:23 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_char(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 10 && nb >= 0)
		ft_char(nb + 48);
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
		ft_char(nb + 48);
	}
	else if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		ft_char('-');
		ft_putnbr(-nb);
	}
}
