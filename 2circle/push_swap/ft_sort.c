/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:24:09 by juson             #+#    #+#             */
/*   Updated: 2022/09/08 19:14:20 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_size_two(t_list **a)
{
	if ((*a)->n > (*a)->next->n)
		sa(a);
}

void	a_size_three(t_list **a, t_stack *stack)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->n;
	mid = (*a)->next->n;
	bot = (*a)->prev->n;
	if ((top > mid) && (mid < bot) && (bot > top))
		sa(a);
	else if ((top > mid) && (mid < bot) && (bot < top))
		ra(a, stack);
	else if ((top < mid) && (mid > bot) && (bot < top))
		rra(a, stack);
	else if ((top < mid) && (mid > bot) && (bot > top))
	{
		sa(a);
		ra(a, stack);
	}
	else if ((top > mid) && (mid > bot) && (bot < top))
	{
		sa(a);
		rra(a, stack);
	}
}

void	sort_prepare(t_list **a, t_list **b, t_stack *stack)
{
	int	pivot1;
	int	pivot2;
	int	init_a_size;

	init_a_size = stack->a_size;
	pivot1 = stack->arr[init_a_size / 3 - 1];
	pivot2 = stack->arr[init_a_size * 2 / 3 - 1];
	while (init_a_size)
	{
		if (stack->a_top->n > pivot2)
			ra(a, stack);
		else
		{
			pb(a, b, stack);
			if (stack->b_top->n <= pivot1)
				rb(b, stack);
		}
		init_a_size--;
	}
	while (stack->a_size > 3)
		pb(a, b, stack);
	a_size_three(a, stack);
}

void	a_size_more_than_three(t_list **a, t_list **b, t_stack *stack)
{
	while (stack->b_size)
	{
		stack_a_rotate(a, stack);
		pa(a, b, stack);
	}
	while (stack->a_top->n > stack->a_bot->n)
		rra(a, stack);
}
