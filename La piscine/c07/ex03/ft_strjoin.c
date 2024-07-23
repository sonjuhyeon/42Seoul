/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:09:53 by juson             #+#    #+#             */
/*   Updated: 2022/02/21 18:44:55 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	while (src[i])
		dest[dest_len++] = src[i++];
	dest[dest_len] = src[i];
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*return_val;
	int		strs_len;
	int		total_len;
	int		i;

	strs_len = 0;
	i = 0;
	if (size <= 0)
	{
		return_val = (char *)malloc(1);
		*return_val = 0;
		return (return_val);
	}
	while (i < size)
		strs_len += ft_strlen(strs[i++]);
	total_len = strs_len + ((size - 1) * ft_strlen(sep));
	return_val = (char *)malloc(total_len + 1);
	ft_strcpy(return_val, strs[0]);
	i = 1;
	while (i < size)
		return_val = ft_strcat(ft_strcat(return_val, sep), strs[i++]);
	return_val[total_len] = '\0';
	return (return_val);
}
