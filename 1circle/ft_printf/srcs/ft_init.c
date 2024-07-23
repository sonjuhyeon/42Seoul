/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:55:02 by juson             #+#    #+#             */
/*   Updated: 2022/05/10 16:17:42 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_fg(t_flag *fg)
{
	fg->zero_padding = 0;
	fg->width = 0;
	fg->precision = -1;
	fg->align = 0;
	fg->blank = 0;
	fg->plus = 0;
	fg->sharp = 0;
	fg->dot = 0;
}

void	init_ft_printf(t_flag *fg)
{
	fg->ret_val = 0;
	fg->i = 0;
}
