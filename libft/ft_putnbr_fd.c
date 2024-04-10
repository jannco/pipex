/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:42:57 by yadereve          #+#    #+#             */
/*   Updated: 2023/10/18 20:11:33 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_nb_pos(int n)
{
	if (n < 0)
		return (n * (-1));
	else
		return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
	}
	nb = ft_nb_pos(n);
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
		ft_putchar_fd(nb + '0', fd);
}
/*
int	main()
{
	int	fd;
	int	n = 00000;

	fd = open("file.txt", O_RDWR |O_CREAT, 0644);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	printf("fd = %d\n", fd);
	ft_putnbr_fd(n, fd);
	close(fd);
	return (0);
} */
