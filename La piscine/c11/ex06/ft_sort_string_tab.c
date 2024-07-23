/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:39:44 by juson             #+#    #+#             */
/*   Updated: 2022/02/23 16:35:00 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int	strs_count(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	j;
	int	strs_n;

	i = 0;
	strs_n = strs_count(tab);
	while (i + 1 < strs_n)
	{
		j = i + 1;
		while (j < strs_n)
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
				swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}
