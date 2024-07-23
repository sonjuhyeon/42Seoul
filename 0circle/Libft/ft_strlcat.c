/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:19:21 by juson             #+#    #+#             */
/*   Updated: 2022/03/31 10:07:51 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;
	size_t	init_dst;

	i = 0;
	dst_len = ft_strlen(dst);
	init_dst = dst_len;
	src_len = ft_strlen(src);
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	while (src[i] && dstsize - init_dst - 1 > i)
		dst[dst_len++] = src[i++];
	if (dst_len < dstsize)
		dst[dst_len] = '\0';
	return (src_len + init_dst);
}
