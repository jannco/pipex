/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:28:10 by yadereve          #+#    #+#             */
/*   Updated: 2024/04/16 16:16:56 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <errno.h>
# include <sys/wait.h>

# define READ_END 0
# define WRITE_END 1

void	free_split(char **str);
void	error_msg(char *str, char **cmd, int code, int fd[2]);
char	**find_path(char **envp);
void	get_path(char **path, char **cmd, char **envp);
char	**ft_split_cmd(char *str, char c);
int		is_quote(char *str);
char	**parsing_cmd( char *str);
void	child_process1(char **argv, int fd[2], char **envp);
void	child_process2(int argc, char **argv, int fd[2], char **envp);
int		main(int argc, char **argv, char **envp);

#endif
