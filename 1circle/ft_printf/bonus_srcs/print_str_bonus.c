/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:34:00 by juson             #+#    #+#             */
/*   Updated: 2022/05/10 16:34:07 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_str_validation(t_flag *fg)
{
	if (fg->blank == 1 || fg->zero_padding == 1
		|| fg->plus == 1 || fg->sharp == 1)
		return (0);
	return (1);
}

void	str_fg_set(t_flag *fg, int len)
{
	if (fg->dot == 1 && fg->precision == -1)
		fg->precision = 0;
	if (fg->dot == 1)
	{
		if (fg->precision > len)
			fg->precision = len;
	}
	else
	{
		if (fg->precision < len)
			fg->precision = len;
	}
}

void	str_padding(t_flag *fg, char *str)
{
	int	i;

	i = 0;
	if (fg->align == 1)
	{
		write(1, str, fg->precision);
		while (i < (fg->width - fg->precision))
		{
			write(1, " ", 1);
			i++;
		}
	}
	else
	{
		while (i < (fg->width - fg->precision))
		{
			write(1, " ", 1);
			i++;
		}
		write(1, str, fg->precision);
	}
	fg->ret_val += fg->width;
}

int	ft_print_str(t_flag *fg)
{
	char	*str;
	int		str_len;

	str = va_arg(fg->ap, char *);
	if (str == 0)
		str = "(null)";
	str_len = ft_strlen(str);
	if (ft_str_validation(fg))
	{
		str_fg_set(fg, str_len);
		if (fg->width > fg->precision)
			str_padding(fg, str);
		else
		{
			write(1, str, fg->precision);
			fg->ret_val += fg->precision;
		}
		return (1);
	}
	return (0);
}
