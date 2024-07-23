/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:47:06 by juson             #+#    #+#             */
/*   Updated: 2022/05/10 16:18:16 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(t_flag *fg)
{
	int	n;
	int	n_len;

	n = va_arg(fg->ap, int);
	n_len = ft_n_base_len(n, 10);
	if (ft_int_validation(fg, n))
	{
		if ((fg->width < fg->precision) || (fg->width < n_len))
		{
			int_sign_print(fg, n);
			int_zero_padding(fg, n, n_len);
		}
		else
			int_align(fg, n, n_len);
		return (1);
	}
	return (0);
}
