/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:03:24 by juson             #+#    #+#             */
/*   Updated: 2022/03/30 16:16:43 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	s_len;
	char			*ret_val;

	i = 0;
	s_len = ft_strlen(s);
	ret_val = (char *)malloc(sizeof(char) * (s_len + 1));
	if (ret_val == 0)
		return (0);
	while (i < s_len)
	{
		ret_val[i] = f(i, s[i]);
		i++;
	}
	ret_val[i] = 0;
	return (ret_val);
}
