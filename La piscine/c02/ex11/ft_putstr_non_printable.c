/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:41:29 by juson             #+#    #+#             */
/*   Updated: 2022/02/10 11:36:59 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hexa(int n)
{
	char	c;

	if (n < 10)
	{
		c = n + 48;
		write(1, &c, 1);
	}
	else
	{
		c = n + 87;
		write(1, &c, 1);
	}
}

void	hexa(char c)
{
	int	a;

	a = (int)c;
	if (a < 0)
		a += 256;
	write(1, "\\", 1);
	print_hexa(a / 16);
	print_hexa(a % 16);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 126)
			write (1, &str[i], 1);
		else
			hexa(str[i]);
		i++;
	}
}
