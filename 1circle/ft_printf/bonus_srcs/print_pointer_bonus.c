/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:33:47 by juson             #+#    #+#             */
/*   Updated: 2022/05/10 19:31:10 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_pointer_validation(t_flag *fg)
{
	if (fg->blank == 1 || fg->plus == 1 || fg->sharp == 1
		|| fg->precision >= 0 || fg->zero_padding == 1)
		return (0);
	return (1);
}

void	pointer_align(t_flag *fg, unsigned long long n, int n_len)
{
	int	i;

	i = 0;
	if (fg->align == 1)
	{
		write(1, "0x", 2);
		ft_unsigned_putnbr_base(n, "0123456789abcdef");
		while (i++ < (fg->width - 2 - n_len))
		{
			write(1, " ", 1);
			fg->ret_val++;
		}
	}
	else
	{
		while (i++ < (fg->width - 2 - n_len))
		{
			write(1, " ", 1);
			fg->ret_val++;
		}
		write(1, "0x", 2);
		ft_unsigned_putnbr_base(n, "0123456789abcdef");
	}
	fg->ret_val += (n_len + 2);
}

int	ft_print_pointer(t_flag *fg)
{
	void		*addr;
	long long	n;
	int			n_len;

	addr = va_arg(fg->ap, void *);
	n = (long long)addr;
	n_len = ft_unsigned_n_base_len(n, 16);
	if (ft_pointer_validation(fg))
	{
		if (fg->width < n_len)
		{
			write(1, "0x", 2);
			ft_unsigned_putnbr_base(n, "0123456789abcdef");
			fg->ret_val += (2 + n_len);
		}
		else
			pointer_align(fg, n, n_len);
		return (1);
	}
	return (0);
}
