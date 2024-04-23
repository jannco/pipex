/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:25:54 by yadereve          #+#    #+#             */
/*   Updated: 2024/04/23 18:31:07 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

char	**ft_split_cmd(char *str, char c)
{
	char	**cmd;
	char	**cmd_buff;

	cmd = ft_split(str, c);
	cmd_buff = ft_split(cmd[0], ' ');
	cmd[0] = ft_strdup(cmd_buff[0]);
	free_split(cmd_buff);
	return (cmd);
}

int	is_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			return ('\"');
		else if (str[i] == '\'')
			return ('\'');
		else
			i++;
	}
	return (0);
}

char	**parsing_cmd( char *str)
{
	char	**cmd;

	if (is_quote(str) == '\"')
		cmd = ft_split_cmd(str, '\"');
	else if (is_quote(str) == '\'')
		cmd = ft_split_cmd(str, '\'');
	else
		cmd = ft_split(str, ' ');
	return (cmd);
}
