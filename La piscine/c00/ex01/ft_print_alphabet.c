/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:07:01 by juson             #+#    #+#             */
/*   Updated: 2022/02/03 17:39:54 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	a2z;

	a2z = 'a';
	while (a2z <= 'z')
	{
		write(1, &a2z, 1);
		a2z++;
	}
}
