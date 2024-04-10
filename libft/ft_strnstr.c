/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:49:00 by yadereve          #+#    #+#             */
/*   Updated: 2023/10/06 19:19:54 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while ((to_find[j] == str[i + j]) && str[i + j])
			j++;
		if (to_find[j] == '\0' && (i + j) <= len)
			return ((char *)str + i);
		else if (j > 0)
			j = 0;
		i++;
	}
	if (str[i] == to_find[j])
		return ((char *)str + i);
	return (0);
}
/*
int main()
{
	printf("%s\n", ft_strnstr("aaabcabcd", "abcd", 9));
	printf("%s", strnstr("aaabcabcd", "abcd", 9));
	return(0);
} */
