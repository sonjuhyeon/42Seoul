/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:04:26 by juson             #+#    #+#             */
/*   Updated: 2022/07/04 19:37:37 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **lst)
{
	int	tmp;

	if (*lst == 0)
		return ;
	tmp = (*lst)->n;
	(*lst)->n = (*lst)->next->n;
	(*lst)->next->n = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_list **lst)
{
	int	tmp;

	if (*lst == 0)
		return ;
	tmp = (*lst)->n;
	(*lst)->n = (*lst)->next->n;
	(*lst)->next->n = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	int	tmp_a;
	int	tmp_b;

	if (*a != 0)
	{
		tmp_a = (*a)->n;
		(*a)->n = (*a)->next->n;
		(*a)->next->n = tmp_a;
	}
	if (*b != 0)
	{
		tmp_b = (*b)->n;
		(*b)->n = (*b)->next->n;
		(*b)->next->n = tmp_b;
	}
	write(1, "ss\n", 3);
}
