/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:32:25 by yadereve          #+#    #+#             */
/*   Updated: 2023/10/06 15:18:59 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	i = n;
	d = dest;
	s = src;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (i--)
			d[i] = s[i];
	}
	else
		while (n--)
			*(d++) = *(s++);
	return (dest);
}
/*
int	main(void)
{
	char	src[] = "Hello, Word!";
	char	dest[] = "1234567890123456789";

	printf("To overlap\n");
	ft_memmove(src, dest, 13);
	printf("src: %s\n", src);
	printf("dest: %s\n", dest);

	printf("Overlap, dest before src\n");
	ft_memmove(dest, src, 6);
	printf("src: %s\n", src);
	printf("dest: %s\n", dest);

	printf("Overlap, src before dest\n");
	ft_memmove(src, src + 6, 6);
	printf("src: %s\n", src);
	printf("dest: %s\n", dest);
	return (0);
} */
