/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:13:10 by juson             #+#    #+#             */
/*   Updated: 2022/05/10 16:18:28 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percent_padding(t_flag *fg, char c)
{
	int	i;

	i = 1;
	if (fg->align == 1)
	{
		write(1, "%", 1);
		while (i < fg->width)
		{
			write(1, &c, 1);
			i++;
		}
	}
	else
	{
		while (i < fg->width)
		{
			write(1, &c, 1);
			i++;
		}
		write(1, "%", 1);
	}
	fg->ret_val += fg->width;
}

int	ft_print_percent(t_flag *fg)
{
	char	c;

	if (fg->width > 0)
		c = ' ';
	if (fg->zero_padding == 1)
		c = '0';
	if (fg->align == 1)
		c = ' ';
	if (fg->width > 0)
		percent_padding(fg, c);
	else
	{
		write(1, "%", 1);
		fg->ret_val++;
	}
	return (1);
}
