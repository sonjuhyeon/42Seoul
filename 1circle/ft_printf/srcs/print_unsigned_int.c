/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:14:42 by juson             #+#    #+#             */
/*   Updated: 2022/05/10 18:07:31 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_int_validation(t_flag *fg)
{
	if (fg->blank == 1 || fg->plus == 1 || fg->sharp == 1)
		return (0);
	if (fg->align == 1 && fg->zero_padding == 1)
		return (0);
	if (fg->dot == 1 && fg->precision == -1)
		fg->precision = 0;
	if (fg->precision == -1 && fg->zero_padding == 1)
		fg->precision = fg->width;
	return (1);
}

void	unsigned_int_zero_padding(t_flag *fg, unsigned int n, int n_len)
{
	int	i;

	i = 0;
	if (fg->precision > n_len)
	{
		while (i < (fg->precision - n_len))
		{
			write(1, "0", 1);
			fg->ret_val++;
			i++;
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
	ft_putnbr_base(n, "0123456789");
	fg->ret_val += n_len;
}

void	unsigned_int_blank_padding(t_flag *fg, int n_len)
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

int	ft_print_unsigned_int(t_flag *fg)
{
	unsigned int	n;
	int				n_len;

	n = va_arg(fg->ap, unsigned int);
	n_len = ft_unsigned_n_base_len(n, 10);
	if (ft_unsigned_int_validation(fg))
	{
		if ((fg->width < fg->precision) || (fg->width < n_len))
			unsigned_int_zero_padding(fg, n, n_len);
		else
		{
			if (fg->align == 1)
			{
				unsigned_int_zero_padding(fg, n, n_len);
				unsigned_int_blank_padding(fg, n_len);
			}
			else
			{
				unsigned_int_blank_padding(fg, n_len);
				unsigned_int_zero_padding(fg, n, n_len);
			}
		}
		return (1);
	}
	return (0);
}
