/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:44:50 by yadereve          #+#    #+#             */
/*   Updated: 2023/10/18 18:41:06 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}
/*
int	main()
{
	int	fd;
	char c = 'a';

	fd = open ("file.txt", O_RDWR);
	if (fd == -1)
		return (-1);
	printf("fd = %d\n", fd);
	ft_putchar_fd(c, fd);
	close(fd);
	return (0);
} */
