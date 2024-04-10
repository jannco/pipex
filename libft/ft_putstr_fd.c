/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:25:25 by yadereve          #+#    #+#             */
/*   Updated: 2024/03/13 16:19:15 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s && fd)
	{
		while (s[i])
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}
/*
int	main()
{
	int		fd;
	char	*s = "Hello world!";

	fd = open("file.txt", O_RDWR);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	printf("fd = %d\n", fd);
	ft_putstr_fd(s, fd);
	close(fd);
	return (0);
} */
