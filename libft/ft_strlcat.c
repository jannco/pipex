/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:26:10 by yadereve          #+#    #+#             */
/*   Updated: 2023/10/06 16:53:05 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	dest_i;
	size_t	destl;
	size_t	srcl;

	i = 0;
	dest_i = 0;
	while (dest[dest_i] != '\0')
		dest_i++;
	destl = dest_i;
	while (src[i] != '\0')
		i++;
	srcl = i;
	i = 0;
	if (destsize <= destl)
		return (srcl + destsize);
	while (src[i] != '\0' && i < (destsize - destl - 1))
	{
		dest[dest_i] = src[i];
		i++;
		dest_i++;
	}
	dest[dest_i] = '\0';
	return (destl + srcl);
}
/*
int main()
{
    char first[] = "This is ";
    char last[] = "a potentially long string";
    int r;
    int size = 16;
    char buffer[size];

    strcpy(buffer,first);
    r = ft_strlcat(buffer, last, size);

    puts(buffer);
    printf("Value returned: %d\n",r);
    if( r > size )
        puts("String truncated");
    else
        puts("String was fully copied");

    return(0);
} */
