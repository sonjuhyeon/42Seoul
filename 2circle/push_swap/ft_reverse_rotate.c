/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:01:33 by juson             #+#    #+#             */
/*   Updated: 2022/07/07 18:14:38 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **a, t_stack *stack)
{
	if (*a == 0)
		return ;
	*a = (*a)->prev;
	stack->a_top = *a;
	stack->a_bot = (*a)->prev;
	write(1, "rra\n", 4);
}

void	rrb(t_list **b, t_stack *stack)
{
	if (*b == 0)
		return ;
	*b = (*b)->prev;
	stack->b_top = *b;
	stack->b_bot = (*b)->prev;
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b, t_stack *stack)
{
	if (*a != 0)
	{
		*a = (*a)->prev;
		stack->a_top = *a;
		stack->a_bot = (*a)->prev;
	}
	if (*b != 0)
	{
		*b = (*b)->prev;
		stack->b_top = *b;
		stack->b_bot = (*b)->prev;
	}
	write(1, "rrr\n", 4);
}
