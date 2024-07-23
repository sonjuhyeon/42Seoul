/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 13:58:20 by juson             #+#    #+#             */
/*   Updated: 2022/04/08 15:32:06 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret_val;
	int		i;
	int		s1_len;
	int		s2_len;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret_val = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (ret_val == 0)
		return (0);
	ft_strlcpy(ret_val, s1, s1_len + 1);
	ft_strlcat(ret_val, s2, s1_len + s2_len + 1);
	return (ret_val);
}
