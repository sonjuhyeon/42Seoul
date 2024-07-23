/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:05:00 by hyojeong          #+#    #+#             */
/*   Updated: 2022/02/05 18:05:03 by hyojeong         ###   ########.fr       */
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
	print_row(x, 'A', 'B', 'A');
	if (y == 1)
		return ;
	while (y-- >= 3)
		print_row(x, 'B', ' ', 'B');
	print_row(x, 'C', 'B', 'C');
}
