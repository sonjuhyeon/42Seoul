/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:26:58 by juson             #+#    #+#             */
/*   Updated: 2022/08/29 20:07:16 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a, t_stack *stack)
{
	if (*a == 0 || stack->a_size == 1)
		return ;
	stack->a_top = (*a)->next;
	stack->a_bot = *a;
	*a = (*a)->next;
	write(1, "ra\n", 3);
}

void	rb(t_list **b, t_stack *stack)
{
	if (*b == 0 || stack->b_size == 1)
		return ;
	stack->b_top = (*b)->next;
	stack->b_bot = *b;
	*b = (*b)->next;
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b, t_stack *stack)
{
	if (*a != 0 || stack->a_size == 1)
	{
		stack->a_top = (*a)->next;
		stack->a_bot = *a;
		*a = (*a)->next;
	}
	if (*b != 0 || stack->b_size == 1)
	{
		stack->b_top = (*b)->next;
		stack->b_bot = *b;
		*b = (*b)->next;
	}
	write(1, "rr\n", 3);
}
