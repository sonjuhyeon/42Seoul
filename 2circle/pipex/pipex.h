/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:16:24 by juson             #+#    #+#             */
/*   Updated: 2022/06/19 13:20:22 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

int		w_count(const char *str, char charset);
int		w_len(const char *str, char charset);
void	all_free(char **strs);
char	*input_data(const char *str, char c, char **ret_val);
char	**ft_split(char const *s, char c);

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*path_join(char *dir, char *cmd);

#endif
