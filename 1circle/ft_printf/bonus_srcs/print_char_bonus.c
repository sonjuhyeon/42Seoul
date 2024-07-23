/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:32:27 by juson             #+#    #+#             */
/*   Updated: 2022/05/10 16:32:33 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_char_validation(t_flag *fg)
{
	if (fg->blank == 1 || fg->zero_padding == 1 || fg->plus == 1
		|| fg->sharp == 1 || fg->precision >= 0)
		return (0);
	return (1);
}

void	char_padding(t_flag *fg, char c)
{
	int	i;

	i = 1;
	if (fg->align == 1)
	{
		write(1, &c, 1);
		while (i < fg->width)
		{
			write(1, " ", 1);
			i++;
		}
	}
	else
	{
		while (i < fg->width)
		{
			write(1, " ", 1);
			i++;
		}
		write(1, &c, 1);
	}
	fg->ret_val += fg->width;
}

int	ft_print_char(t_flag *fg)
{
	char	c;

	c = va_arg(fg->ap, int);
	if (ft_char_validation(fg))
	{
		if (fg->width > 0)
			char_padding(fg, c);
		else
		{
			write(1, &c, 1);
			fg->ret_val++;
		}
		return (1);
	}
	return (0);
}
