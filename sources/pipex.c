/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:25:54 by yadereve          #+#    #+#             */
/*   Updated: 2024/04/17 20:01:34 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>

// 	STDIN_FILENO = 0
// 	STDOUT_FILENO = 1
// 	STDERR_FILENO = 2

#define READ_END 0
#define WRITE_END 1

int	checker_path(char **path)
{
	(void)path;
	return(0);
}

void	free_split(char **str)
{
	int i;

	i = -1;
	while (++i)
	{
		free(str[i]);
	}
	free(str);
}

char *get_path(char **envp)
{
	int		i = 0;
	char	**path;
	char	*str;

	while (envp[i])
	{
		if (ft_strncmp (envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	envp[i] = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	path = ft_split(envp[i], ':');
	i = checker_path(path);
	str = path[i];
	free_split(path);
	return (str);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	f1 = 0;
	int	f2 = 0;
	pid_t	id;
	pid_t	id2;
	char *cmd1[] = {"ls", "-l", NULL};
	char *cmd2[] = {"cat", "-e", NULL};
	int	status;
	char	*path;

	(void)argv;
	(void)argc;
	path = get_path(envp);
	printf("%s", path);
	free(path);
	status = 0;
	pipe(fd);
	if (fd < 0)
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
		f1 = open("infile", O_RDONLY);
		if (f1 < 0)
			perror("failed to open infile");
		dup2(f1, STDIN_FILENO);
		dup2(fd[WRITE_END], STDOUT_FILENO);
		if (fd[WRITE_END] >= 0)
			close(fd[WRITE_END]);
		if (f1 >= 0)
			close(f1);
		if (execve("/usr/bin/ls", cmd1, envp) == -1)
			perror("failed Id_1");
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
		f2 = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (f1 < 0)
			perror("failed to create/open outfile");
		dup2(f2, STDOUT_FILENO);
		dup2(fd[READ_END], STDIN_FILENO);
		if (fd[READ_END] >= 0)
			close(fd[READ_END]);
		if (f2 >= 0)
			close(f2);
		if (execve("/usr/bin/cat", cmd2, envp) == -1)
			perror("failed Id_2");
	}
	close(fd[READ_END]);
	close(fd[WRITE_END]);
	close(f1);
	close(f2);
	waitpid(id, NULL, 0);
	waitpid(id2, &status, 0);
	return (WEXITSTATUS(status));
}
