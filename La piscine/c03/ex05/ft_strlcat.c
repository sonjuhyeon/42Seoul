/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:43:00 by juson             #+#    #+#             */
/*   Updated: 2022/02/12 19:38:58 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	str_len(char *str)
{
	unsigned int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	init_dest;

	i = 0;
	dest_len = str_len(dest);
	init_dest = dest_len;
	src_len = str_len(src);
	if (dest_len >= size)
		return (size + src_len);
	while (src[i] && size - init_dest - 1 > i)
		dest[dest_len++] = src[i++];
	if (dest_len < size)
		dest[dest_len] = '\0';
	return (src_len + init_dest);
}
