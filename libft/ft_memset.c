/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:02:05 by yadereve          #+#    #+#             */
/*   Updated: 2023/10/06 17:38:57 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*dtr;

	i = 0;
	dtr = str;
	while (n > i)
	{
		dtr[i] = c;
		i++;
	}
	return (str);
}
/*
#include <string.h>

int main () {
	char str[40];

	strcpy(str,"This is string.h library function");
	puts(str);

	memset(str,'#',7);
	puts(str);

	ft_memset(str,'$',7);
	puts(str);

	return(0);
} */
