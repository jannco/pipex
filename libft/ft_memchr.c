/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:02:49 by yadereve          #+#    #+#             */
/*   Updated: 2023/10/06 18:56:46 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const char	*s;
	char		ch;
	size_t		i;

	i = 0;
	ch = c;
	s = str;
	while (i < n)
	{
		if (s[i] == ch)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
/*
int main () {
	const char str[] = "https://www.tutorialspoint.com";
	const char ch = '.';
	char *ret1;
	char *ret2;
	int len = 12;

	ret1 = memchr(str, ch, len);
	ret2 = ft_memchr(str, ch, len);

	printf("or: String after |%c| is - |%s|\n", ch, ret1);
	printf("my: String after |%c| is - |%s|\n", ch, ret2);

	return(0);
} */
