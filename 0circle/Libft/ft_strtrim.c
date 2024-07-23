/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:29:32 by juson             #+#    #+#             */
/*   Updated: 2022/03/30 16:15:11 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	int		i;
	char	*ret_val;

	start = 0;
	end = ft_strlen(s1) - 1;
	i = 0;
	if (set == 0 || s1 == 0)
	{
		ret_val = (char *)malloc(sizeof(char) * (end + 1));
		ret_val = (char *)s1;
		return (ret_val);
	}
	if (s1[0] == 0)
		return ((char *)s1);
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	while (ft_strrchr(set, s1[end]) && end > start)
		end--;
	ret_val = (char *)malloc(sizeof(char) * (end - start + 2));
	if (ret_val == 0)
		return (0);
	ft_strlcpy(ret_val, &s1[start], end - start + 2);
	return (ret_val);
}
