/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:40:36 by juson             #+#    #+#             */
/*   Updated: 2022/03/30 16:12:58 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	seperator(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	else if (c == '-' || c == '+')
		return (2);
	else if (c >= '0' && c <= '9')
		return (3);
	else
		return (0);
}

int	c2i(char n)
{
	int	nbr;

	nbr = n - '0';
	return (nbr);
}

int	check_ll_over(unsigned long long val, int sign)
{
	unsigned long long	ll_max;

	ll_max = 9223372036854775807;
	if (val > ll_max && sign == 1)
		return (-1);
	if (val > ll_max && sign == -1)
		return (0);
	return (val * sign);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	value;

	i = 0;
	sign = 1;
	value = 0;
	while (seperator(str[i]) == 1)
		i++;
	if (seperator(str[i]) == 2)
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (seperator(str[i]) == 3)
		value = value * 10 + c2i(str[i++]);
	value = check_ll_over(value, sign);
	return (value);
}
