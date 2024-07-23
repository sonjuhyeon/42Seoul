/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:45:28 by juson             #+#    #+#             */
/*   Updated: 2022/02/23 10:45:35 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	nbr = n - 48;
	return (nbr);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	value;

	i = 0;
	sign = 1;
	value = 0;
	while (seperator(str[i]) == 1)
		i++;
	if (seperator(str[i]) == 0)
		return (0);
	while (seperator(str[i]) == 2)
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (seperator(str[i]) != 3)
		return (0);
	while (seperator(str[i]) == 3)
		value = value * 10 + c2i(str[i++]);
	value *= sign;
	return (value);
}
