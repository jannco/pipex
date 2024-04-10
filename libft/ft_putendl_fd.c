/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:32:14 by yadereve          #+#    #+#             */
/*   Updated: 2023/10/18 18:52:33 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
/*
int	main()
{
	int fd;
	char *s = "hello world!";

	fd = open("file.txt", O_RDWR);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	printf("fd = %d\n", fd);
	ft_putendl_fd(s, fd);
	close(fd);
	return (0);
} */
