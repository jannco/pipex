/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:00:17 by yadereve          #+#    #+#             */
/*   Updated: 2023/10/04 15:05:01 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	char		ch;
	const char	*str;

	ch = c;
	i = ft_strlen(s);
	str = s + i;
	while (i-- >= 0)
	{
		if (*str == ch)
			return ((char *)str);
		str--;
	}
	if (c == '\0')
		return ((char *)str);
	return (0);
}
/*
int	main(void)
{
	char	c = 'b';
	char	*str = "bonjour";

	printf("%s\n", ft_strrchr(str, c));
	printf("%s", strrchr(str, c));
} */
