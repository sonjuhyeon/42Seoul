/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:47:27 by juson             #+#    #+#             */
/*   Updated: 2022/02/12 13:39:14 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str || !to_find)
		return (0);
	if (to_find[0] == '\0')
		return (&str[0]);
	while (str[i])
	{
		if (str[i] == to_find[j])
		{
			while (to_find[j] && str[i + j] && to_find[j] == str[i + j])
				j++;
			if (to_find[j] == '\0')
				return (&str[i]);
			j = 0;
		}
		i++;
	}
	return (0);
}
