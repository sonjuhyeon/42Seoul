/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:55:12 by juson             #+#    #+#             */
/*   Updated: 2022/03/30 16:13:14 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ret_val;

	ret_val = (char *)malloc(count * size);
	if (ret_val == 0)
		return (0);
	ft_memset(ret_val, 0, count * size);
	return ((void *)ret_val);
}
