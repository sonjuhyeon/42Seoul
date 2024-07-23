/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:19:09 by juson             #+#    #+#             */
/*   Updated: 2022/07/11 15:52:36 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_error(t_list **a, t_list *a_bot)
{
	write(2, "Error\n", 6);
	ft_lstclear(a, a_bot);
	exit(1);
}

void	num_check(t_list **a, int num, t_list *a_bot)
{
	t_list	*tmp;

	tmp = *a;
	while ((tmp != a_bot) && (tmp != 0))
	{
		if (num == tmp->n)
			ft_ps_error(a, a_bot);
		tmp = tmp->next;
	}
}

void	sort_check(t_list *a, t_list *a_bot)
{
	t_list	*tmp;

	tmp = a->next;
	while ((a != a_bot) && (a != 0))
	{
		if (tmp->n < a->n)
			return ;
		tmp = tmp->next;
		a = a->next;
	}
	exit(0);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*array_sort(t_list *a, t_stack stack)
{
	int	*val;
	int	i;

	i = 0;
	val = malloc(sizeof(int) * stack.a_size);
	if (val == 0)
		return (0);
	while (i < stack.a_size)
	{
		val[i] = a->n;
		a = a->next;
		i++;
	}
	ft_sort_int_tab(val, stack.a_size);
	return (val);
}
