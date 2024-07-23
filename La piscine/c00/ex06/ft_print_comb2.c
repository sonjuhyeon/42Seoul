/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:44:21 by juson             #+#    #+#             */
/*   Updated: 2022/02/05 17:39:35 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_ab(int n)
{
	char	c;

	c = n / 10 + 48;
	write(1, &c, 1);
	c = n % 10 + 48;
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (a <= 98)
	{
		while (b <= 99)
		{
			print_ab(a);
			write(1, " ", 1);
			print_ab(b);
			if (a == 98 && b == 99)
				return ;
			else
				write(1, ", ", 2);
			b++;
		}
		a++;
		b = a + 1;
	}
}
