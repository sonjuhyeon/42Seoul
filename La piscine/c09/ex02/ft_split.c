/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:49:03 by juson             #+#    #+#             */
/*   Updated: 2022/02/21 18:43:32 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	find_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	w_count(char *str, char *charset, int i)
{
	int	word_count;

	word_count = 0;
	while (str[i])
	{
		while (str[i] && find_charset(str[i], charset) == 0)
			i++;
		if (str[i] && find_charset(str[i], charset) == 1)
			word_count += 1;
		while (str[i] && find_charset(str[i], charset) == 1)
			i++;
	}
	return (word_count);
}

int	w_len(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && find_charset(str[i], charset))
		i++;
	return (i);
}

char	*input_data(char *str, char *charset, int *word_len)
{
	int		i;
	char	*return_val;

	i = 0;
	*word_len = w_len(str, charset);
	return_val = (char *)malloc(*word_len + 1);
	while (str[i] && find_charset(str[i], charset))
	{
		return_val[i] = str[i];
		i++;
	}
	return_val[i] = '\0';
	return (return_val);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**return_val;
	int		word_count;
	int		word_len;

	i = 0;
	j = 0;
	word_len = 0;
	word_count = w_count(str, charset, 0);
	return_val = (char **)malloc(sizeof(char *) * (word_count + 1));
	while (str[i])
	{
		while (str[i] && find_charset(str[i], charset) == 0)
			i++;
		if (str[i] && find_charset(str[i], charset) == 1)
			return_val[j] = input_data(&str[i], charset, &word_len);
		i += word_len;
		j++;
		word_len = 0;
	}
	return_val[word_count] = 0;
	return (return_val);
}
