/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:24:48 by yadereve          #+#    #+#             */
/*   Updated: 2024/03/23 12:11:22 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freebuffer(int *flag, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i])
	{
		if (!*flag)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			*flag = 0;
		buffer[i++] = '\0';
	}
}

static size_t	ft_strlen_line(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

static char	*ft_strjoin_line(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)malloc((ft_strlen_line(s1) + ft_strlen_line(s2) + 1)
			* sizeof(char));
	if (!str)
		return (free(s1), NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i++] = s2[j];
		if (s2[j++] == '\n')
			break ;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			i;
	int			flag;

	i = 0;
	flag = 1;
	if (fd >= FOPEN_MAX || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (fd > 0 && fd < FOPEN_MAX && read(fd, 0, 0) >= 0)
			while (BUFFER_SIZE > i)
				buffer[fd][i++] = '\0';
		return (NULL);
	}
	line = NULL;
	while (flag && (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE)))
	{
		line = ft_strjoin_line(line, buffer[fd]);
		ft_freebuffer(&flag, buffer[fd]);
		if (!line)
			return (NULL);
	}
	return (line);
}
/*
int	main(int	argc, char	**argv)
{
	int		fd[argc - 1];
	char	*line;
	int		i = 0;
	int		flag = 0;

	line = NULL;
	if (argc <= 1)
	{
		write(1, "Write some arguments\n", 21);
		return (1);
	}
	while (i < (argc - 1))
	{
		fd[i] = open(argv[i + 1], O_RDONLY);
		i++;
	}
	i = 0;
	while (flag == (argc - 1))
	{
		line = get_next_line(fd[i++]);
		if (!line)
			printf("Line: %s", line);
		if (i == (argc - 1))
			i = 0;
		if (i < argc && !line)
			flag++;
	}
	while (!i)
		close(fd[i--]);
	return (0);
} */
