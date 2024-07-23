/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:32:28 by juson             #+#    #+#             */
/*   Updated: 2022/03/30 16:11:18 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	int	ret_val;

	if (c >= 'A' && c <= 'Z')
	{
		ret_val = c - 'A' + 'a';
		return (ret_val);
	}
	return (c);
}
