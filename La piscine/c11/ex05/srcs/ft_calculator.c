/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:27:07 by juson             #+#    #+#             */
/*   Updated: 2022/02/23 15:42:58 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putnbr(int nb);
void	ft_putstr(char *str);

void	ft_add(int a, int b)
{
	ft_putnbr(a + b);
}

void	ft_sub(int a, int b)
{
	ft_putnbr(a - b);
}

void	ft_mul(int a, int b)
{
	ft_putnbr(a * b);
}

void	ft_div(int a, int b)
{
	if (b != 0)
		ft_putnbr(a / b);
	else
		ft_putstr("Stop : division by zero");
}

void	ft_mod(int a, int b)
{
	if (b != 0)
		ft_putnbr(a % b);
	else
		ft_putstr("Stop : modulo by zero");
}
