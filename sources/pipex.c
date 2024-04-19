/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:25:54 by yadereve          #+#    #+#             */
/*   Updated: 2024/04/19 08:27:18 by yadereve         ###   ########.fr       */
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

	i = 0;
	while (path[i])
	{
		path_buff = ft_strjoin(path[i], "/");
		path[i] = ft_strjoin(path_buff, cmd[0]);
		free(path_buff);
		if (execve(path[i], cmd, envp) == 0)
			break ;
		i++;
	}
	if (execve(path[i], cmd, envp) == -1)
		perror("failed Id");
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
	int		f1;
	int		f2;
	pid_t	id;
	pid_t	id2;
	char	**cmd1;
	char	**cmd2;
	int		status;
	char	**path;

	f1 = 0;
	f2 = 0;
	cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[3], ' ');
	path = find_path(envp);
	status = 0;
	pipe(fd);
	if (pipe(fd) < 0)
		perror("failed to create pipe");
	id = fork();
	if (id < 0)
		perror("Fork");
	if (id == 0)
	{
		// Child process
		// exit(127);
		if (fd[READ_END] >= 0)
			close(fd[READ_END]);
		f1 = open(argv[1], O_RDONLY);
		if (f1 < 0)
			perror("failed to open infile");
		dup2(f1, STDIN_FILENO);
		dup2(fd[WRITE_END], STDOUT_FILENO);
		if (fd[WRITE_END] >= 0)
			close(fd[WRITE_END]);
		if (f1 >= 0)
			close(f1);
		get_path(path, cmd1, envp);
	}
	id2 = fork();
	if (id2 < 0)
		perror("Fork");
	if (id2 == 0)
	{
		// Child 2 process
		// exit(126);
		if (fd[WRITE_END] >= 0)
			close(fd[WRITE_END]);
		f2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (f1 < 0)
			perror("failed to create/open outfile");
		dup2(f2, STDOUT_FILENO);
		dup2(fd[READ_END], STDIN_FILENO);
		if (fd[READ_END] >= 0)
			close(fd[READ_END]);
		if (f2 >= 0)
			close(f2);
		get_path(path, cmd2, envp);
	}
	free_split(path);
	free_split(cmd1);
	free_split(cmd2);
	close(fd[READ_END]);
	close(fd[WRITE_END]);
	close(f1);
	close(f2);
	waitpid(id, NULL, 0);
	waitpid(id2, &status, 0);
	return (WEXITSTATUS(status));
}
