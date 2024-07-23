/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:56:13 by juson             #+#    #+#             */
/*   Updated: 2022/02/09 11:35:28 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_array(int *array, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(array[i] + 48);
		i++;
	}
	if (array[0] != 10 - n)
		write (1, ", ", 2);
}

void	recursive(int array[], int n, int i)
{
	if (i == 0)
		array[i] = 0;
	else
		array[i] = array[i - 1] + 1;
	while (array[i] <= 10 - n + i)
	{
		if (i == n - 1)
			print_array(array, n);
		else
			recursive(array, n, i + 1);
		array[i] = array[i] + 1;
	}
}

void	ft_print_combn(int n)
{
	int	array[10];
	int	i;

	i = 0;
	recursive(array, n, i);
}
