/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:36:05 by juson             #+#    #+#             */
/*   Updated: 2022/03/29 18:28:32 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == 0)
		return ((char *)&haystack[0]);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[j])
		{
			while (needle[j] && haystack[i + j] && needle[j] == haystack[i + j]
				&& i + j < len)
				j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
			j = 0;
		}
		i++;
	}
	return (0);
}
