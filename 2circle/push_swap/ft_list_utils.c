/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:31:10 by juson             #+#    #+#             */
/*   Updated: 2022/07/07 17:08:26 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == 0)
		return (0);
	new->n = content;
	new->prev = new;
	new->next = new;
	return (new);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	if (new == 0)
		return ;
	if (*lst != 0)
	{
		new->next = *lst;
		*lst = (*lst)->prev;
		(*lst)->next = new;
		new->prev = *lst;
		*lst = tmp;
		(*lst)->prev = new;
		*lst = new;
	}
	else
		*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new, t_list *lst_bot)
{
	t_list	*tmp;

	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	(*lst)->prev = new;
	while ((*lst != lst_bot) && (*lst)->next != 0)
		*lst = (*lst)->next;
	(*lst)->next = new;
	new->prev = *lst;
	new->next = tmp;
	*lst = tmp;
}

void	ft_lstclear(t_list **lst, t_list *lst_bot)
{
	t_list	*tmp;

	if (*lst == 0 || lst_bot == 0)
		return ;
	while ((*lst != lst_bot))
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	free(*lst);
}
