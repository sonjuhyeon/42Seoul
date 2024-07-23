/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 08:47:56 by juson             #+#    #+#             */
/*   Updated: 2022/02/20 14:57:40 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ans_print(int array[], int i)
{
	char	c;

	while (i < 10)
	{
		c = array[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	return (1);
}

int	queen_ck(int array[], int row, int column)
{
	int	i;

	i = 0;
	while (i < column)
	{
		if (array[i] == row)
			return (0);
		if (array[i] - row == i - column)
			return (0);
		if (array[i] - row == column - i)
			return (0);
		i++;
	}
	return (1);
}

void	ft_recursive(int array[], int *count, int row, int column)
{
	int		i;

	if (column == 10)
	{
		ans_print(array, 0);
		*count += 1;
		return ;
	}
	i = row;
	while (i < 10)
	{
		if (queen_ck(array, i, column))
		{
			array[column] = i;
			ft_recursive(array, count, 0, column + 1);
			if (i + 1 < 10)
				ft_recursive(array, count, i + 1, column);
			return ;
		}
		i++;
	}
	return ;
}

int	ft_ten_queens_puzzle(void)
{
	int		count;
	int		array[10];

	count = 0;
	ft_recursive(array, &count, 0, 0);
	return (count);
}
