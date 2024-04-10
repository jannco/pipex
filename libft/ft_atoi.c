/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:53:43 by yadereve          #+#    #+#             */
/*   Updated: 2023/10/06 17:36:08 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	menus;

	menus = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-')
	{
		menus = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * menus);
}
/*
int	main()
{
	printf("%d\n", ft_atoi("\f\n\r\t\v  -2147483648++ "));
	printf("%d\n", atoi("\f\n\r\t\v  -2147483648++ "));
	printf("INT_MIN: %d\n", INT_MIN);
	printf("INT_MAX: %d", INT_MAX);
} */
