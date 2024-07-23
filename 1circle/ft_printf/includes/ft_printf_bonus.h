/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:23:21 by juson             #+#    #+#             */
/*   Updated: 2022/05/10 19:28:30 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_flag
{
	va_list	ap;
	int		i;
	int		ret_val;

	int		zero_padding;
	int		width;
	int		precision;
	int		align;
	int		blank;
	int		plus;
	int		sharp;
	int		dot;
}	t_flag;

int		ft_printf(const char *s, ...);
int		flag_check(t_flag *fg, const char *s);
void	width_and_precision_ck(t_flag *fg, const char *s);
int		ft_printf_atoi(t_flag *fg, const char *s);
int		parameter_print(t_flag *fg, const char *s);

void	init_fg(t_flag *fg);
void	init_ft_printf(t_flag *fg);

int		ft_print_percent(t_flag *fg);
void	percent_padding(t_flag *fg, char c);

int		ft_print_char(t_flag *fg);
int		ft_char_validation(t_flag *fg);
void	char_padding(t_flag *fg, char c);

int		ft_print_str(t_flag *fg);
int		ft_str_validation(t_flag *fg);
void	str_fg_set(t_flag *fg, int len);
void	str_padding(t_flag *fg, char *str);

int		ft_print_unsigned_int(t_flag *fg);
int		ft_unsigned_int_validation(t_flag *fg);
void	unsigned_int_zero_padding(t_flag *fg, unsigned int n, int n_len);
void	unsigned_int_blank_padding(t_flag *fg, int n_len);

int		ft_print_hexa(t_flag *fg, char x_type);
int		ft_hexa_validation(t_flag *fg);
void	hexa_zero_padding(t_flag *fg, unsigned int n, int n_len, char x_type);
void	hexa_blank_padding(t_flag *fg, int n_len);
void	print_option_sharp(t_flag *fg, unsigned int n);

int		ft_print_int(t_flag *fg);
int		ft_int_validation(t_flag *fg, int n);
void	int_sign_print(t_flag *fg, int n);
void	int_zero_padding(t_flag *fg, int n, int n_len);
void	int_blank_padding(t_flag *fg, int n_len);
void	int_align(t_flag *fg, int n, int n_len);

int		ft_print_pointer(t_flag *fg);
int		ft_pointer_validation(t_flag *fg);
void	pointer_align(t_flag *fg, unsigned long long n, int n_len);

int		ft_strlen(const char *str);
int		ft_n_base_len(long long n, int base);
int		ft_unsigned_n_base_len(long long n, int base);
void	ft_putnbr_base(long long nb, char *base);
void	ft_unsigned_putnbr_base(unsigned long long nb, char *base);

#endif
