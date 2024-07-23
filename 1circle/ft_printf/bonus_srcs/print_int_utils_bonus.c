/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:33:15 by juson             #+#    #+#             */
/*   Updated: 2022/05/10 16:33:20 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_int_validation(t_flag *fg, int n)
{
	if (fg->sharp == 1)
		return (0);
	if ((fg->align == 1 && fg->zero_padding == 1))
		return (0);
	if (fg->dot == 1 && fg->precision == -1)
		fg->precision = 0;
	if (fg->plus == 1 || fg->blank == 1 || n < 0)
		fg->width--;
	if (fg->precision == -1 && fg->zero_padding == 1)
		fg->precision = fg->width;
	return (1);
}

void	int_sign_print(t_flag *fg, int n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		fg->ret_val++;
	}
	else
	{
		if (fg->blank == 1)
			write(1, " ", 1);
		if (fg->plus == 1)
			write(1, "+", 1);
		if (fg->blank == 1 || fg->plus == 1)
			fg->ret_val++;
	}
}

void	int_zero_padding(t_flag *fg, int n, int n_len)
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

void	int_blank_padding(t_flag *fg, int n_len)
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

void	int_align(t_flag *fg, int n, int n_len)
{
	if (fg->align == 1)
	{
		int_sign_print(fg, n);
		int_zero_padding(fg, n, n_len);
		int_blank_padding(fg, n_len);
	}
	else
	{
		int_blank_padding(fg, n_len);
		int_sign_print(fg, n);
		int_zero_padding(fg, n, n_len);
	}
}
