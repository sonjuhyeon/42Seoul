/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:35:59 by juson             #+#    #+#             */
/*   Updated: 2022/07/06 17:51:45 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	w_count(const char *str, char charset, t_list **a, t_list *a_bot)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == charset)
			i++;
		if (str[i] && str[i] != charset)
			word_count += 1;
		while (str[i] && str[i] != charset)
			i++;
	}
	if (word_count == 0)
		ft_ps_error(a, a_bot);
	return (word_count);
}

int	w_len(const char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != charset)
		i++;
	return (i);
}

void	all_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	*input_data(const char *str, char c, char **ret_val)
{
	int		i;
	char	*return_val;

	i = 0;
	return_val = (char *)malloc(w_len(str, c) + 1);
	if (return_val == 0)
	{
		all_free(ret_val);
		return (0);
	}
	while (str[i] && str[i] != c)
	{
		return_val[i] = str[i];
		i++;
	}
	return_val[i] = '\0';
	return (return_val);
}

char	**ft_split(char const *s, char c, t_list **a, t_list *a_bot)
{
	int		i;
	int		j;
	int		wc;
	char	**ret_val;

	i = 0;
	j = 0;
	wc = w_count(s, c, a, a_bot);
	ret_val = (char **)malloc(sizeof(char *) * (wc + 1));
	if (ret_val == 0)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			ret_val[j] = input_data(&s[i], c, ret_val);
		if (ret_val == 0)
			return (0);
		while (s[i] && s[i] != c)
			i++;
		j++;
	}
	ret_val[wc] = 0;
	return (ret_val);
}
