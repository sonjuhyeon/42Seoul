/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:45:16 by juson             #+#    #+#             */
/*   Updated: 2022/02/23 18:59:01 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"

void	num_print(int a, int b, char c, void(*cal[5])(int, int))
{
	if (c == '+')
		cal[0](a, b);
	if (c == '-')
		cal[1](a, b);
	if (c == '*')
		cal[2](a, b);
	if (c == '/')
		cal[3](a, b);
	if (c == '%')
		cal[4](a, b);
	ft_putstr("\n");
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int		a;
	int		b;
	int		sign_len;
	void	(*cal[5])(int, int);

	cal[0] = &ft_add;
	cal[1] = &ft_sub;
	cal[2] = &ft_mul;
	cal[3] = &ft_div;
	cal[4] = &ft_mod;
	sign_len = ft_strlen(argv[2]);
	if (argc == 4)
	{
		if ((argv[2][0] == '+' || argv[2][0] == '-' || argv[2][0] == '*'
			|| argv[2][0] == '/' || argv[2][0] == '%') && sign_len == 1)
		{
			a = ft_atoi(argv[1]);
			b = ft_atoi(argv[3]);
			num_print(a, b, argv[2][0], cal);
			return (0);
		}
		ft_putstr("0\n");
		return (0);
	}
	return (0);
}
