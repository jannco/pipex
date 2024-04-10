/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:39:51 by yadereve          #+#    #+#             */
/*   Updated: 2023/10/15 12:24:39 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
char	f(unsigned int i, char c)
{
	return (char)(i + c);
}

int	main()
{
	char*	str2;

	str2 = ft_strmapi("abcd0 ", *f);
	printf("or: |abcd0 | -> |aceg4%%|\n");
	printf("my: |abcd0 | -> |%s|\n", str2);
	free(str2);
	str2 = ft_strmapi("", *f);
	printf("or: || -> ||\n");
	printf("my: || -> |%s|", str2);
	free(str2);
	return (0);
} */
