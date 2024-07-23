/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 08:47:56 by juson             #+#    #+#             */
/*   Updated: 2022/02/15 20:24:10 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ans_print(int array[4][4], int i, int j)
{
	char	c;

	while (i < 4)
	{
		while (j < 4)
		{
			if (array[i][j] == 1)
			{
				c = j + '0';
				write(1, &c, 1);
			}
			j++;
		}
		i++;
		j = 0;
	}
	write(1, "\n", 1);
}

int	queen_ck(int array[4][4], int i, int j)
{
	int	row;
	int	col;

	row = 0;
	while (row < i)
	{
		col = 0;
		while (col < 4)
		{
			if ((row - i == row - j) || (row - i == j - row))
			{
				if (array[i][j] == 1)
					return (0);
			}
			col++;
		}
		row++;
	}
	return (1);
}

void	row_init(int array[4])
{
	int	n;

	n = 0;
	while (n < 4)
		array[n++] = 0;
}

void	ft_recursive(int array[4][4], int *count, int i, int j)
{
	if (i == 4)
	{
		ans_print(array, 0, 0);
		*count += 1;
	}
	while (j < 4)
	{
		array[i][j] = 1;
		if (queen_ck(array, i, j))
		{
			ft_recursive(array, count, i++, j);
		}
		else
		{
			row_init(array[i]);
			ft_recursive(array, count, i, j++);
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	array[4][4];
	int	i;
	int	j;
	int	*count;
	int	n;

	i = 0;
	j = 0;
	n = 0;
	count = &n;
	while (i < 4)
	{
		while (j < 4)
			array[i][j++] = 0;
		i++;
		j = 0;
	}
	ft_recursive(array, count, 0, 0);
	return (n);
}

int	main(void)
{
	int answer;

	answer = ft_ten_queens_puzzle();
	printf("724 : %d\n",answer);
}
