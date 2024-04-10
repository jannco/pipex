/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:24:25 by yadereve          #+#    #+#             */
/*   Updated: 2023/10/20 11:24:35 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	s_len;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start)
		len = 0;
	if (s_len - start < len)
		len = s_len - start;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (i < len && s[i + start])
	{
		result[i] = s[i + start];
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
int main()
{
	char *s;

	s = ft_substr("hello", 0, 5);
	printf("%s", s);
	free(s);
} */
