/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:58:32 by juson             #+#    #+#             */
/*   Updated: 2022/05/10 18:47:20 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_atoi(t_flag *fg, const char *s)
{
	int	value;

	value = 0;
	while (s[fg->i] >= '0' && s[fg->i] <= '9')
	{
		value = value * 10 + (s[fg->i] - '0');
		if (value < 0)
			return (0);
		fg->i++;
	}
	return (value);
}

void	width_and_precision_ck(t_flag *fg, const char *s)
{
	if (s[fg->i] >= '0' && s[fg->i] <= '9')
		fg->width = ft_printf_atoi(fg, s);
	if (s[fg->i] == '.')
	{
		fg->dot = 1;
		fg->i++;
	}
	if (s[fg->i] >= '0' && s[fg->i] <= '9')
		fg->precision = ft_printf_atoi(fg, s);
}

int	parameter_print(t_flag *fg, const char *s)
{
	int	ret;

	if (s[fg->i] == '%')
		ret = ft_print_percent(fg);
	else if (s[fg->i] == 'c')
		ret = ft_print_char(fg);
	else if (s[fg->i] == 's')
		ret = ft_print_str(fg);
	else if (s[fg->i] == 'u')
		ret = ft_print_unsigned_int(fg);
	else if (s[fg->i] == 'x' || s[fg->i] == 'X')
	{
		if (fg->sharp == 1)
			if (s[fg->i] == 'X')
				fg->sharp = 2;
		ret = ft_print_hexa(fg, s[fg->i]);
	}
	else if (s[fg->i] == 'd' || s[fg->i] == 'i')
		ret = ft_print_int(fg);
	else if (s[fg->i] == 'p')
		ret = ft_print_pointer(fg);
	else
		ret = 0;
	return (ret);
}

int	flag_check(t_flag *fg, const char *s)
{
	fg->i++;
	init_fg(fg);
	while (s[fg->i] == ' ' || s[fg->i] == '-' || s[fg->i] == '+'
		|| s[fg->i] == '#' || s[fg->i] == '0')
	{
		if (s[fg->i] == ' ')
			fg->blank = 1;
		else if (s[fg->i] == '-')
			fg->align = 1;
		else if (s[fg->i] == '+')
			fg->plus = 1;
		else if (s[fg->i] == '#')
			fg->sharp = 1;
		else
			fg->zero_padding = 1;
		fg->i++;
	}
	width_and_precision_ck(fg, s);
	if (parameter_print(fg, s) == 0)
		return (0);
	return (1);
}

int	ft_printf(const char *s, ...)
{
	t_flag	fg;

	init_ft_printf(&fg);
	va_start(fg.ap, s);
	if (s == NULL)
		return (-1);
	while (s[fg.i])
	{
		if (s[fg.i] == '%')
		{
			if (flag_check(&fg, s) == 0)
			{
				va_end(fg.ap);
				return (-1);
			}
		}
		else
		{
			write(1, &s[fg.i], 1);
			fg.ret_val++;
		}
		fg.i++;
	}
	va_end(fg.ap);
	return (fg.ret_val);
}
