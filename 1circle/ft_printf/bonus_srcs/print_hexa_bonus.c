/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:32:43 by juson             #+#    #+#             */
/*   Updated: 2022/05/10 18:31:53 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_hexa_validation(t_flag *fg)
{
	if (fg->blank == 1 || fg->plus == 1)
		return (0);
	if (fg->align == 1 && fg->zero_padding == 1)
		return (0);
	if (fg->dot == 1 && fg->precision == -1)
		fg->precision = 0;
	if (fg->sharp > 0)
		fg->width -= 2;
	if (fg->precision == -1 && fg->zero_padding == 1)
		fg->precision = fg->width;
	return (1);
}

void	print_option_sharp(t_flag *fg, unsigned int n)
{
	if (n != 0)
	{
		if (fg->sharp == 1)
			write(1, "0x", 2);
		if (fg->sharp == 2)
			write(1, "0X", 2);
		if (fg->sharp == 1 || fg->sharp == 2)
			fg->ret_val += 2;
	}
}

void	hexa_zero_padding(t_flag *fg, unsigned int n, int n_len, char x_type)
{
	int	i;

	i = 0;
	print_option_sharp(fg, n);
	if (fg->precision > n_len)
	{
		while (i++ < (fg->precision - n_len))
		{
			write(1, "0", 1);
			fg->ret_val++;
		}
	}
	if (n == 0 && fg->dot == 1 && fg->precision <= 0)
	{
		if (fg->width <= 0)
			return ;
		write(1, " ", 1);
		fg->ret_val++;
		return ;
	}
	if (x_type == 'x')
		ft_putnbr_base(n, "0123456789abcdef");
	else
		ft_putnbr_base(n, "0123456789ABCDEF");
	fg->ret_val += n_len;
}

void	hexa_blank_padding(t_flag *fg, int n_len)
{
	int	i;

	i = 0;
	if ((fg->width > n_len) && (fg->width > fg->precision))
	{
		if (fg->precision > n_len)
		{
			while (i < (fg->width - fg->precision))
			{
				write(1, " ", 1);
				fg->ret_val++;
				i++;
			}
		}
		else if (fg->width > n_len)
		{
			while (i < (fg->width - n_len))
			{
				write(1, " ", 1);
				fg->ret_val++;
				i++;
			}
		}
	}
}

int	ft_print_hexa(t_flag *fg, char x_type)
{
	unsigned int	n;
	int				n_len;

	n = va_arg(fg->ap, unsigned int);
	n_len = ft_unsigned_n_base_len(n, 16);
	if (ft_hexa_validation(fg))
	{
		if ((fg->width < fg->precision) || (fg->width < n_len))
			hexa_zero_padding(fg, n, n_len, x_type);
		else
		{
			if (fg->align == 1)
			{
				hexa_zero_padding(fg, n, n_len, x_type);
				hexa_blank_padding(fg, n_len);
			}
			else
			{
				hexa_blank_padding(fg, n_len);
				hexa_zero_padding(fg, n, n_len, x_type);
			}
		}
		return (1);
	}
	return (0);
}
