/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:44:16 by juson             #+#    #+#             */
/*   Updated: 2022/02/22 20:19:07 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sign(int *tab, int len)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i + 1 < len)
	{
		tmp = tab[i] - tab[i + 1];
		if (tmp == 0)
		{
			i++;
			continue ;
		}
		if (tmp < 0)
			return (1);
		else
			return (-1);
	}
	return (0);
}

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	tmp;
	int	sign;

	i = 0;
	sign = ft_sign(tab, length);
	while (i + 1 < length)
	{
		tmp = f(tab[i], tab[i + 1]);
		if (tmp == 0)
		{
			i++;
			continue ;
		}
		if ((sign == 1 && tmp > 0) || (sign == -1 && tmp < 0))
			return (0);
		i++;
	}
	return (1);
}
