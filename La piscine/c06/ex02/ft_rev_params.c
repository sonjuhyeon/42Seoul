/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 09:04:35 by juson             #+#    #+#             */
/*   Updated: 2022/02/14 09:48:07 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		i++;
		j = 0;
		write(1, "\n", 1);
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	int		rev_time;
	char	*tmp;

	rev_time = (argc - 1) / 2;
	i = 1;
	while (i <= rev_time)
	{
		tmp = argv[i];
		argv[i] = argv[argc - i];
		argv[argc - i] = tmp;
		i++;
	}
	ft_print(argc, argv);
	return (0);
}
