/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:25:54 by yadereve          #+#    #+#             */
/*   Updated: 2024/04/19 11:07:46 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>

// 	STDIN_FILENO = 0
// 	STDOUT_FILENO = 1
// 	STDERR_FILENO = 2

void	free_split(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		free(str[i]);
	}
	free(str);
}

void	error_message(char *str, char **cmd, int code, int fd[2])
{
	ft_putstr_fd(str, STDERR_FILENO);
	if (cmd)
		ft_putendl_fd(cmd[0], STDERR_FILENO);
	else
		ft_putchar_fd('\n', STDERR_FILENO);
	if (fd != 0)
	{
		if (fd[WRITE_END] >= 0)
			close(fd[WRITE_END]);
		if (fd[READ_END] >= 0)
			close(fd[READ_END]);
	}
	if (cmd)
		free_split(cmd);
	exit (code);
}


char	**find_path(char **envp)
{
	int		i;
	char	*path_buff;
	char	**path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp (envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	path_buff = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	path = ft_split(path_buff, ':');
	free(path_buff);
	return (path);
}

void	get_path(char **path, char **cmd, char **envp)
{
	int		i;
	char	*path_buff;
	int		fd;

	i = 0;
	if (ft_strncmp("/usr/bin/", cmd[0], 9) == 0
		|| ft_strncmp("/bin/", cmd[0], 5) == 0)
		execve(cmd[0], cmd, envp);
	else
	{
		while (path[i])
		{
			path_buff = ft_strjoin(path[i], "/");
			path[i] = ft_strjoin(path_buff, cmd[0]);
			fd = open(path[i], O_RDONLY);
			free(path_buff);
			if (fd >= 0)
				execve(path[i], cmd, envp);
			i++;
		}
	}
	free_split(path);
	error_message("pipex: command not found: ", cmd, 127, 0);
}

// char	*parsing_cmd(int argc, char **argv)
// {
// 	char cmd[2][3] = {
// 		{"ls", "-l", NULL},
// 		{"cat", "-e", NULL}
// 	};
// 	int		i;

// 	// cmd[0] = (char*[]){"ls", "-l", NULL};
// 	// cmd[1] = (char*[]){"cat", "-e", NULL};
// 	i = 2;
// 	while (argv[i])
// 	{
// 		if (i >= argc)
// 			break ;
// 		i++;
// 	}
// 	printf("%d\n", i);
// 	return (cmd);
// }

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		infile;
	int		outfile;
	pid_t	id;
	pid_t	id2;
	char	**cmd1;
	char	**cmd2;
	int		status;
	char	**path;

	if (argc != 5)
		error_message("Invalid number of arguments", NULL, 1, 0);
	infile = 0;
	outfile = 0;
	cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[3], ' ');
	path = find_path(envp);
	status = 0;
	pipe(fd);
	if (pipe(fd) < 0)
	{
		free_split(cmd1);
		free_split(cmd2);
		free_split(path);
		error_message("failed to open pipe", NULL, 1, 0);
	}
	id = fork();
	if (id < 0)
		perror("Fork");
	if (id == 0)
	{
		// Child 1 process
		free_split(cmd2);
		if (fd[READ_END] >= 0)
			close(fd[READ_END]);
		infile = open(argv[1], O_RDONLY);
		if (infile < 0)
			error_message("No such file or directory", NULL, 1, fd);
		dup2(infile, STDIN_FILENO);
		dup2(fd[WRITE_END], STDOUT_FILENO);
		if (fd[WRITE_END] >= 0)
			close(fd[WRITE_END]);
		if (infile >= 0)
			close(infile);
		get_path(path, cmd1, envp);
	}
	id2 = fork();
	if (id2 < 0)
		perror("Fork");
	if (id2 == 0)
	{
		// Child 2 process
		free_split(cmd1);
		if (fd[WRITE_END] >= 0)
			close(fd[WRITE_END]);
		outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (outfile < 0)
			error_message("failed to open outfile", NULL, 1, fd);
		dup2(outfile, STDOUT_FILENO);
		dup2(fd[READ_END], STDIN_FILENO);
		if (fd[READ_END] >= 0)
			close(fd[READ_END]);
		if (outfile >= 0)
			close(outfile);
		get_path(path, cmd2, envp);
	}
	free_split(path);
	free_split(cmd1);
	free_split(cmd2);
	close(fd[READ_END]);
	close(fd[WRITE_END]);
	waitpid(id, NULL, 0);
	waitpid(id2, &status, 0);
	return (WEXITSTATUS(status));
}
