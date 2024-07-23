/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:40:52 by juson             #+#    #+#             */
/*   Updated: 2022/09/05 19:51:46 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

#include <stdio.h>

typedef struct s_list
{
	int				n;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	int		*arr;

	int		a_size;
	t_list	*a_top;
	t_list	*a_bot;

	int		b_size;
	t_list	*b_top;
	t_list	*b_bot;
}	t_stack;

int		ft_atoi(const char *str, t_list **a, t_list *a_bot);
int		seperator(char c);
int		check_int_over(long long val, int sign, t_list **a, t_list *a_bot);

char	**ft_split(char const *s, char c, t_list **a, t_list *a_bot);
int		w_count(const char *str, char charset, t_list **a, t_list *a_bot);
int		w_len(const char *str, char charset);
void	all_free(char **strs);
char	*input_data(const char *str, char c, char **ret_val);

t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new, t_list *lst_bot);
void	ft_lstclear(t_list **lst, t_list *lst_bot);

void	ft_ps_error(t_list **a, t_list *a_bot);
void	num_check(t_list **a, int num, t_list *a_bot);
void	sort_check(t_list *a, t_list *a_bot);
void	ft_sort_int_tab(int *tab, int size);
int		*array_sort(t_list *a, t_stack stack);

void	sa(t_list **lst);
void	sb(t_list **lst);
void	ss(t_list **a, t_list **b);

void	pa(t_list **a, t_list **b, t_stack *stack);
void	pb(t_list **a, t_list **b, t_stack *stack);

void	ra(t_list **a, t_stack *stack);
void	rb(t_list **b, t_stack *stack);
void	rr(t_list **a, t_list **b, t_stack *stack);

void	rra(t_list **a, t_stack *stack);
void	rrb(t_list **b, t_stack *stack);
void	rrr(t_list **a, t_list **b, t_stack *stack);

void	a_size_two(t_list **a);
void	a_size_three(t_list **a, t_stack *stack);
void	sort_prepare(t_list **a, t_list **b, t_stack *stack);
void	a_size_more_than_three(t_list **a, t_list **b, t_stack *stack);

void	stack_a_rotate(t_list **a, t_stack *stack);
void	stack_a_min_rotate(t_list **a, t_stack *stack);
int		get_min_rotate(t_list *a, t_stack *stack);

#endif
