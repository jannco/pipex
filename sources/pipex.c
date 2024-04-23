/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:25:54 by yadereve          #+#    #+#             */
/*   Updated: 2024/04/23 18:31:35 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_msg(char *str, char **cmd, int code, int fd[2])
{
	ft_putstr_fd(str, STDERR_FILENO);
	(void)str;
	if (cmd)
	{
		ft_putendl_fd(cmd[0], STDERR_FILENO);
		free_split(cmd);
	}
	else
		ft_putchar_fd('\n', STDERR_FILENO);
	if (fd != 0)
	{
		if (fd[WRITE_END] >= 0)
			close(fd[WRITE_END]);
		if (fd[READ_END] >= 0)
			close(fd[READ_END]);
	}
	exit (code);
}

void	get_path(char **path, char **cmd, char **envp)
{
	int		i;
	char	*path_buff;
	int		fd;

	i = -1;
	if (!ft_strncmp("/usr/bin/", cmd[0], 9) || !ft_strncmp("/bin/", cmd[0], 5))
		execve(cmd[0], cmd, envp);
	else
	{
		while (path[++i])
		{
			path_buff = ft_strjoin(path[i], "/");
			path[i] = ft_strjoin(path_buff, cmd[0]);
			fd = open(path[i], O_RDONLY);
			free(path_buff);
			if (fd >= 0)
			{
				execve(path[i], cmd, envp);
				close(fd);
				exit(EXIT_FAILURE);
			}
		}
	}
	free_split(path);
	error_msg("pipex: command not found: ", cmd, 127, 0);
}

void	child_process1(char **argv, int fd[2], char **envp)
{
	int		infile;
	char	**cmd1;
	char	**path;

	infile = 0;
	path = find_path(envp);
	cmd1 = parsing_cmd(argv[2]);
	if (fd[READ_END] >= 0)
		close(fd[READ_END]);
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		error_msg("pipex: input: No such file or directory", NULL, 2, fd);
	dup2(infile, STDIN_FILENO);
	dup2(fd[WRITE_END], STDOUT_FILENO);
	if (fd[WRITE_END] >= 0)
		close(fd[WRITE_END]);
	if (infile >= 0)
		close(infile);
	get_path(path, cmd1, envp);
}

void	child_process2(int argc, char **argv, int fd[2], char **envp)
{
	int		outfile;
	char	**cmd2;
	char	**path;

	outfile = 0;
	path = find_path(envp);
	cmd2 = parsing_cmd(argv[3]);
	if (fd[WRITE_END] >= 0)
		close(fd[WRITE_END]);
	outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		error_msg("pipex: failed to open/create outfile", NULL, 2, fd);
	dup2(outfile, STDOUT_FILENO);
	dup2(fd[READ_END], STDIN_FILENO);
	if (fd[READ_END] >= 0)
		close(fd[READ_END]);
	if (outfile >= 0)
		close(outfile);
	get_path(path, cmd2, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	id;
	pid_t	id2;
	int		status;

	if (argc != 5)
		error_msg("pipex: Invalid number of arguments", NULL, 1, 0);
	status = 0;
	if (pipe(fd) < 0)
		error_msg("pipex: failed to open pipe", NULL, 2, 0);
	id = fork();
	if (id < 0)
		error_msg("pipex: fork error", NULL, 2, 0);
	if (id == 0)
		child_process1(argv, fd, envp);
	id2 = fork();
	if (id2 < 0)
		error_msg("pipex: fork error", NULL, 2, 0);
	if (id2 == 0)
		child_process2(argc, argv, fd, envp);
	close(fd[READ_END]);
	close(fd[WRITE_END]);
	waitpid(id, NULL, 0);
	waitpid(id2, &status, 0);
	return (WEXITSTATUS(status));
}
