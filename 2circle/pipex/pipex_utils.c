/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:13:30 by juson             #+#    #+#             */
/*   Updated: 2022/06/19 13:20:13 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == 0)
		return ((char *)&s[i]);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	i = 0;
	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	while ((tmp_s1[i] || tmp_s2[i]) && i < n)
	{
		if (tmp_s1[i] != tmp_s2[i])
			return (tmp_s1[i] - tmp_s2[i]);
		i++;
	}
	return (0);
}

char	*path_join(char *dir, char *cmd)
{
	char	*path;
	int		i;
	int		j;

	i = -1;
	j = 0;
	path = malloc(ft_strlen(dir) + ft_strlen(cmd) + 2);
	if (path == 0)
		return (0);
	while (dir[++i])
		path[i] = dir[i];
	path[i] = '/';
	while (cmd[j])
		path[++i] = cmd[j++];
	path[++i] = '\0';
	return (path);
}
