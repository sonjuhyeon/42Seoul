/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:32:58 by juson             #+#    #+#             */
/*   Updated: 2022/02/16 15:10:29 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*return_src;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	return_src = (char *)malloc(len + 1);
	while (src[i])
	{
		return_src[i] = src[i];
		i++;
	}
	return_src[i] = src[i];
	return (return_src);
}
