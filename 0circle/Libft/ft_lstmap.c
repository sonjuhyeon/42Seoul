/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:14:01 by juson             #+#    #+#             */
/*   Updated: 2022/03/30 16:22:20 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*ret_val;

	ret_val = 0;
	while (lst)
	{
		new = ft_lstnew(f(lst -> content));
		if (new == 0)
		{
			ft_lstclear(&ret_val, del);
			return (0);
		}
		ft_lstadd_back(&ret_val, new);
		lst = lst -> next;
	}
	return (ret_val);
}
