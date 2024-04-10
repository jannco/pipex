/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:14:58 by yadereve          #+#    #+#             */
/*   Updated: 2023/10/12 15:36:24 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len != 0 && ft_strchr(set, s1[len]))
		len--;
	result = ft_substr(s1, 0, len + 1);
	if (!result)
		return ((NULL));
	return (result);
}
/*
int main()
{
	char	*str;

	str = ft_strtrim("lorem ipsum dolor sit amet", "te");
	puts(str);
	free(str);
} */
