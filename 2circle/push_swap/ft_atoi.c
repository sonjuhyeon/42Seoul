/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:36:16 by juson             #+#    #+#             */
/*   Updated: 2022/07/06 18:15:50 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	seperator(char c)
{
	if (c == '-' || c == '+')
		return (1);
	else if (c >= '0' && c <= '9')
		return (2);
	else
		return (0);
}

int	check_int_over(long long val, int sign, t_list **a, t_list *a_bot)
{
	long long	int_max;
	long long	int_min;

	int_max = INT_MAX;
	int_min = INT_MIN;
	if ((val > int_max && sign == 1) || (val < int_min && sign == -1))
		ft_ps_error(a, a_bot);
	return (val);
}

int	ft_atoi(const char *str, t_list **a, t_list *a_bot)
{
	int			i;
	int			sign;
	long long	value;

	i = 0;
	sign = 1;
	value = 0;
	if (seperator(str[i]) == 1)
	{
		if (str[i] == '-')
			sign = -1;
		i++;
		if (str[i] == 0)
			ft_ps_error(a, a_bot);
	}
	while (seperator(str[i]) == 2 && i < 11)
		value = value * 10 + (str[i++] - '0');
	if (str[i] != '\0')
		ft_ps_error(a, a_bot);
	value *= sign;
	check_int_over(value, sign, a, a_bot);
	return (value);
}
