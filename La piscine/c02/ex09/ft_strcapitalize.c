/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:12:38 by juson             #+#    #+#             */
/*   Updated: 2022/02/10 09:06:36 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	find_word(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (2);
	else if (c >= '0' && c <= '9')
		return (3);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (find_word(str[i]) == 1 && j == 0)
			str[i] -= 32;
		if (find_word(str[i]) == 2 && j == 1)
			str[i] += 32;
		if (find_word(str[i]))
			j = 1;
		else
			j = 0;
		i++;
	}
	return (str);
}
