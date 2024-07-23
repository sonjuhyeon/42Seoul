/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:03:49 by juson             #+#    #+#             */
/*   Updated: 2022/03/30 16:23:00 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	s_len;

	s_len = ft_strlen(s);
	if (s == 0 || fd < 0)
		return ;
	write(fd, s, s_len);
	write(fd, "\n", 1);
}
