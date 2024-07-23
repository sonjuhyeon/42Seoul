/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:01:48 by juson             #+#    #+#             */
/*   Updated: 2022/09/12 15:54:10 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack, t_list **a, t_list **b)
{
	stack->a_size = 0;
	stack->a_top = 0;
	stack->a_bot = 0;
	stack->b_size = 0;
	stack->b_top = 0;
	stack->b_bot = 0;
	*a = 0;
	*b = 0;
}

void	list_data_input(t_list **a, char **av, t_stack *stack)
{
	int		i;
	int		n;
	t_list	*tmp;

	i = 0;
	while (av[i])
	{
		n = ft_atoi(av[i], a, stack->a_bot);
		tmp = ft_lstnew(n);
		ft_lstadd_back(a, tmp, stack->a_bot);
		stack->a_top = *a;
		stack->a_bot = (*a)->prev;
		stack->a_size++;
		num_check(a, n, stack->a_bot);
		i++;
	}
}

void	make_list(t_list **a, char **argv, t_stack *stack)
{
	int		i;
	char	**av;

	i = 1;
	while (argv[i])
	{
		av = ft_split(argv[i], ' ', a, stack->a_bot);
		list_data_input(a, av, stack);
		all_free(av);
		i++;
	}
	sort_check(*a, stack->a_bot);
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	t_list	*a;
	t_list	*b;

	init_stack(&stack, &a, &b);
	if (argc >= 2)
	{
		make_list(&a, argv, &stack);
		stack.arr = array_sort(a, stack);
		if (stack.a_size == 2)
			a_size_two(&a);
		else if (stack.a_size == 3)
			a_size_three(&a, &stack);
		else
		{
			sort_prepare(&a, &b, &stack);
			a_size_more_than_three(&a, &b, &stack);
		}
	}
	/*
	if (argc >= 2)
	{
		while (a != stack.a_bot)
		{
			printf("%d\n", a->n);
			a = a->next;
		}
		printf("%d\n", a->n);
		printf("a top : %d\n", stack.a_top->n);
		printf("a bot : %d\n", stack.a_bot->n);
		printf("a size : %d\n", stack.a_size);
		if (b != 0)
		{
			while (b != stack.b_bot)
			{
				printf("%d\n", b->n);
				b = b->next;
			}
			printf("%d\n", b->n);
			printf("b top : %d\n", stack.b_top->n);
			printf("b bot : %d\n", stack.b_bot->n);
			printf("b size : %d\n", stack.b_size);
		}
	}
	free(stack.arr);
	*/
	return (0);
}
