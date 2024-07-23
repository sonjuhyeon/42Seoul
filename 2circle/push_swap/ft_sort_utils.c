/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 19:10:50 by juson             #+#    #+#             */
/*   Updated: 2022/09/08 19:48:10 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_rotate(t_list *a, t_stack *stack)
{
	int	b_top;
	int	a_size;
	int	i;

	b_top = stack->b_top->n;
	i = 0;
	a_size = stack->a_size;
	while (!(a->n > b_top && a->prev->n < b_top))
	{
		i++;
		if ((a->n < a->prev->n) && (a->n > b_top || a->prev->n < b_top))
			break ;
		a = a->next;
	}
	if (a_size / 2 > i)
		return (0);
	else
		return (1);
}

void	stack_a_min_rotate(t_list **a, t_stack *stack)
{
	int	b_top;

	b_top = stack->b_top->n;
	if (get_min_rotate(*a, stack))
	{
		while (!((stack->a_top->n > b_top) && (stack->a_bot->n < b_top)))
		{
			if ((stack->a_top->n < stack->a_bot->n)
				&& (stack->a_top->n > b_top || stack->a_bot->n < b_top))
				break ;
			ra(a, stack);
		}
	}
	else
	{
		while (!((stack->a_top->n > b_top) && (stack->a_bot->n < b_top)))
		{
			if ((stack->a_top->n < stack->a_bot->n)
				&& (stack->a_top->n > b_top || stack->a_bot->n < b_top))
				break ;
			rra(a, stack);
		}
	}
}

void	stack_a_rotate(t_list **a, t_stack *stack)
{
	int	a_top;
	int	a_bot;
	int	b_top;

	a_top = stack->a_top->n;
	a_bot = stack->a_bot->n;
	b_top = stack->b_top->n;
	if (a_top < a_bot)
	{
		if (a_top > b_top)
			return ;
		stack_a_min_rotate(a, stack);
	}
	else
	{
		if (a_top > b_top && a_bot < b_top)
			return ;
		stack_a_min_rotate(a, stack);
	}
}
