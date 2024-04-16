/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:25:54 by yadereve          #+#    #+#             */
/*   Updated: 2024/04/16 18:46:48 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>

// int	main(int ac, char *av[])
// {
// 	(void)av;
// 	(void)ac;
// 	int fd[2];

// 	if (pipe(fd) == -1)
// 	{
// 		return (1);
// 	}
// 	int pid1 = fork();
// 	if (pid1 < 0)
// 	{
// 		return 2;
// 	}
// 	if (pid1 == 0)
// 	{
// 		dup2(fd[1], STDOUT_FILENO);
// 		close(fd[0]);
// 		close(fd[1]);
// 		execlp("ping", "ping", "-c", "5", "google.com", NULL);
// 	}
// 	int pid2 = fork();
// 	printf("pid2 = %d\n", pid2);
// 	if (pid2 < 0)
// 	{
// 		return (3);
// 	}
// 	if (pid2 == 0)
// 	{
// 		dup2(fd[0], STDIN_FILENO);
// 		close(fd[0]);
// 		close(fd[1]);
// 		execlp("grep", "grep", "rtt", NULL);
// 	}
// 	close(fd[0]);
// 	close(fd[1]);
// 	waitpid(pid1, NULL, 0);
// 	waitpid(pid2, NULL, 0);
// 	return (0);
// }

// 	STDIN_FILENO = 0
// 	STDOUT_FILENO = 1
// 	STDERR_FILENO = 2

#define READ_END 0
#define WRITE_END 1

char *get_path
{
	int	i;

	while (envp[i])
	{
		ft_strncmp (envp[i], "PATH=");
		fd = open(envp[i])
		if (fd < 0)
		{
			return false
		}
		retunn (path);
	}

}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	// pid_t	id;
	char *cmd[3] = {"ls", "dhds", NULL};

	(void)argv;
	(void)argc;
	pipe(fd);
	// fd[READ_END];
	// fd[WRITE_END];
	// int i = 0;
	// while (envp[i])
	// 	printf("%s\n", envp[i++]);

	// id = fork();
	// if (id == 0)

	char *path;

	path = get_path(envp);

	if (!path)
	{
		free(fds)
		exit 0
	}

	if (execve(path, cmd, envp) == -1)
		printf("here\n");
	// waitpid(id, NULL, 0);
	// printf("I am parent %d\n", id);
}
