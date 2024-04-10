/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:33:44 by yadereve          #+#    #+#             */
/*   Updated: 2023/10/04 15:04:44 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		if (str1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
/*
#include <string.h>

int main () {
	char str1[] = "ABCDEF";
	char str2[] = "ABCDEF";
	int ret1;
	int ret2;

	ret1 = ft_strncmp(str1, str2, 4);
	ret2 = strncmp(str1, str2, 4);

	printf("%d\n", ret1);
	printf("%d\n", ret2);

	return(0);
} */
