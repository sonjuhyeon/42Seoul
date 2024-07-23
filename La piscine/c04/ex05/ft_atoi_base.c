/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:36:16 by juson             #+#    #+#             */
/*   Updated: 2022/02/14 15:50:05 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| base[i] == '\t' || base[i] == '\n' || base[i] == '\v'
			|| base[i] == '\f' || base[i] == '\r')
			return (0);
		i++;
	}
	*base_len = i;
	while (i <= 1 || *base == '\0')
		return (0);
	return (1);
}

int	get_num(char c, char *base, int *base_len)
{
	int	i;

	i = 0;
	while (i < *base_len && base[i] != c)
		i++;
	if (i == *base_len)
		return (-1);
	return (i);
}

int	trans_int(char *str, char *base, int *base_len)
{
	int	i;
	int	result;
	int	num;

	i = 0;
	result = 0;
	num = get_num(str[i], base, base_len);
	while (num >= 0)
	{
		result = result * *base_len;
		result = result + num;
		i++;
		num = get_num(str[i], base, base_len);
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	len;
	int	*base_len;
	int	sign;
	int	result;

	i = 0;
	len = 0;
	sign = 1;
	base_len = &len;
	result = 0;
	if (base_ck(base, base_len) == 1)
	{
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
			i++;
		while (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign *= -1;
			i++;
		}
		result = trans_int(&str[i], base, base_len);
	}
	return (result * sign);
}
