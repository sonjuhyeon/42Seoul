/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juson <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:39:09 by juson             #+#    #+#             */
/*   Updated: 2022/06/19 12:49:24 by juson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	file_open(char *f_name, int mode)
{
	int	ret;

	if (mode == 0)
	{
		if (access(f_name, F_OK))
		{
			write(2, "zsh: ", 5);
			write(2, "no such file or directory: ", 27);
			write(2, f_name, ft_strlen(f_name));
			write(2, "\n", 1);
			return (0);
		}
		ret = open(f_name, O_RDONLY);
		return (ret);
	}
	else
	{
		ret = open(f_name, O_CREAT | O_TRUNC | O_WRONLY,
				S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
		if (ret < 0)
			exit(1);
		return (ret);
	}
}

char	*get_path(char	**dirs, char *cmd)
{
	char	*path;
	int		i;

	i = 0;
	if (ft_strchr(cmd, '/'))
		return (cmd);
	while (dirs[i])
	{
		path = path_join(dirs[i], cmd);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (path);
}

void	execution(char *cmd, char **envp)
{
	char	**av;
	char	*path;
	char	**dirs;
	int		i;

	i = 0;
	av = ft_split(cmd, ' ');
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	dirs = ft_split(envp[i] + 5, ':');
	path = get_path(dirs, av[0]);
	all_free(dirs);
	execve(path, av, envp);
	write(2, "zsh: ", 5);
	write(2, "command not found: ", 19);
	write(2, av[0], ft_strlen(av[0]));
	write(2, "\n", 1);
	exit(127);
}

void	exec_cmd1(char *cmd, char **envp, int infile)
{
	pid_t	pid;
	int		pipe_fd[2];
	int		state;

	state = pipe(pipe_fd);
	if (state == -1)
		exit(1);
	pid = fork();
	if (pid > 0)
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		waitpid(pid, NULL, WNOHANG);
	}
	else if (pid == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		if (infile == STDIN_FILENO)
			exit(1);
		else
			execution(cmd, envp);
	}
	else
		exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	int		infile;
	int		outfile;

	if (argc == 5)
	{
		infile = file_open(argv[1], 0);
		outfile = file_open(argv[4], 1);
		dup2(infile, STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		exec_cmd1(argv[2], envp, infile);
		execution(argv[3], envp);
	}
	else
	{
		write(2, "Invalid number of arguments\n", 28);
		exit(1);
	}
	return (0);
}
