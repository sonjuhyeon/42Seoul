/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:21:25 by juson             #+#    #+#             */
/*   Updated: 2022/03/29 17:33:12 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	i = len;
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (0);
	if (dst > src)
	{
		while (i > 0)
		{
			tmp_dst[i - 1] = tmp_src[i - 1];
			i--;
		}
	}
	else if (dst < src)
		ft_memcpy(dst, src, len);
	return (dst);
}
