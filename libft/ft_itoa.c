/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:38:43 by yadereve          #+#    #+#             */
/*   Updated: 2023/10/17 16:07:49 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countnum(int n)
{
	int	i;
	int	nb;

	i = 0;
	nb = n;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	if (n <= 0)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		menus;

	i = 0;
	menus = 1;
	if (n < 0)
	{
		menus = -1;
		i++;
	}
	i = ft_countnum(n);
	str = (char *)ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (i - 1 >= 0)
	{
		str[i - 1] = ((n % 10) * menus) + '0';
		n /= 10;
		i--;
	}
	if (menus < 0)
		str[0] = '-';
	return (str);
}
/*
int	main()
{
	char	*str;

	str = ft_itoa(-3879);
	printf("%s\n", str);
	free(str);
} */
