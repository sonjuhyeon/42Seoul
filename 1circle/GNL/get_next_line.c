/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:24:00 by juson             #+#    #+#             */
/*   Updated: 2022/04/14 18:04:10 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

static char	*file_read(char *str, int fd)
{
	char	*buff;
	int		byte;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == 0)
		return (0);
	byte = read(fd, buff, BUFFER_SIZE);
	while (byte > 0)
	{
		buff[byte] = 0;
		str = ft_strjoin(str, buff);
		if (str == 0)
		{
			free(buff);
			return (0);
		}
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte < 0)
			free(str);
	}
	free(buff);
	if (byte < 0)
		return (0);
	return (str);
}

static int	nl_pos(char *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

static char	*get_line(char *str, int next_pos)
{
	int		i;
	char	*ret_val;

	if (str[0] == 0)
		return (0);
	ret_val = (char *)malloc(sizeof(char) * (next_pos + 1));
	if (ret_val == 0)
		return (0);
	i = 0;
	while (i < next_pos)
	{
		ret_val[i] = str[i];
		i++;
	}
	ret_val[i] = 0;
	return (ret_val);
}

static char	*next_str(char *str, int next_pos)
{
	char	*ret_val;
	int		i;

	i = 0;
	if (str[next_pos] == 0)
	{
		free(str);
		return (0);
	}
	ret_val = ft_strdup(&str[next_pos]);
	free(str);
	return (ret_val);
}

char	*get_next_line(int fd)
{
	char		*ret_val;
	static char	*str;
	int			next_pos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = file_read(str, fd);
	if (str == 0)
		return (0);
	next_pos = nl_pos(str);
	ret_val = get_line(str, next_pos);
	str = next_str(str, next_pos);
	return (ret_val);
}
