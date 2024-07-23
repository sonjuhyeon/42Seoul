/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:55:16 by juson             #+#    #+#             */
/*   Updated: 2022/02/21 11:34:58 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	trans_int(char *str, char *base, int *base_len);
int	get_num(char c, char *base, int *base_len);
int	base_ck(char *base, int *base_len);

int	ft_str_len(int n, int base_len)
{
	int			len;
	long long	m;

	len = 1;
	m = n;
	if (m < 0)
	{
		m = -m;
		while (m / base_len)
		{
			m = m / base_len;
			len++;
		}
		return (++len);
	}
	else
	{
		while (m / base_len)
		{
			m = m / base_len;
			len++;
		}
		return (len);
	}
}

char	*itoa(int n, char *base, int base_len)
{
	char		*str;
	int			str_len;
	long long	m;

	str_len = ft_str_len(n, base_len);
	str = (char *)malloc(str_len + 1);
	m = n;
	if (m < 0)
		m = -m;
	str[str_len] = '\0';
	while (0 < str_len)
	{
		str[str_len - 1] = base[m % base_len];
		m /= base_len;
		str_len--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	n;
	int	to_len;
	int	*base_to_len;
	int	from_len;
	int	*base_from_len;

	base_to_len = &to_len;
	base_from_len = &from_len;
	if (base_ck(base_from, base_from_len) && base_ck(base_to, base_to_len))
	{
		n = ft_atoi_base(nbr, base_from);
		return (itoa(n, base_to, to_len));
	}
	return (0);
}
