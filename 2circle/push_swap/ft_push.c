/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:57:54 by juson             #+#    #+#             */
/*   Updated: 2022/09/01 20:48:05 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b, t_stack *stack)
{
	t_list	*tmp;

	if (*b == 0)
		return ;
	tmp = stack->b_top;
	stack->b_top = (*b)->next;
	*b = (*b)->prev;
	(*b)->next = tmp->next;
	*b = tmp->next;
	(*b)->prev = tmp->prev;
	stack->b_size--;
	tmp->prev = tmp;
	tmp->next = tmp;
	ft_lstadd_front(a, tmp);
	stack->a_top = tmp;
	stack->a_bot = (*a)->prev;
	stack->a_size++;
	if (stack->b_size == 0)
	{
		*b = 0;
		stack->b_top = 0;
		stack->b_bot = 0;
	}
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b, t_stack *stack)
{
	t_list	*tmp;

	if (*a == 0)
		return ;
	tmp = stack->a_top;
	stack->a_top = (*a)->next;
	*a = (*a)->prev;
	(*a)->next = tmp->next;
	*a = tmp->next;
	(*a)->prev = tmp->prev;
	stack->a_size--;
	tmp->prev = tmp;
	tmp->next = tmp;
	ft_lstadd_front(b, tmp);
	stack->b_top = tmp;
	stack->b_bot = (*b)->prev;
	stack->b_size++;
	if (stack->a_size == 0)
	{
		*a = 0;
		stack->a_top = 0;
		stack->a_bot = 0;
	}
	write(1, "pb\n", 3);
}
