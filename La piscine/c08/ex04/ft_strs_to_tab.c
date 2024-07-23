/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:40:02 by juson             #+#    #+#             */
/*   Updated: 2022/02/20 17:05:03 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*return_src;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	return_src = (char *)malloc(len + 1);
	while (src[i])
	{
		return_src[i] = src[i];
		i++;
	}
	return_src[i] = src[i];
	return (return_src);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*return_val;
	int			i;

	i = 0;
	return_val = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!return_val)
		return (0);
	while (i < ac)
	{
		return_val[i].size = ft_strlen(av[i]);
		return_val[i].str = av[i];
		return_val[i].copy = ft_strdup(av[i]);
		i++;
	}
	return_val[i].str = 0;
	return (return_val);
}
