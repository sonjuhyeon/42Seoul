/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:31:33 by hyojeong          #+#    #+#             */
/*   Updated: 2022/02/05 17:58:11 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_row(int x, char first, char middle, char last)
{
	ft_putchar(first);
	if (x == 1)
	{
		ft_putchar('\n');
		return ;
	}
	while (x-- >= 3)
		ft_putchar(middle);
	ft_putchar(last);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
		return ;
	print_row(x, '/', '*', '\\');
	if (y == 1)
		return ;
	while (y-- >= 3)
		print_row(x, '*', ' ', '*');
	print_row(x, '\\', '*', '/');
}
