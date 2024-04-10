/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:13:27 by yadereve          #+#    #+#             */
/*   Updated: 2023/11/23 13:28:39 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i += ft_putchar('-');
	}
	if (n < 10)
	{
		i += ft_putchar(n + '0');
	}
	else
	{
		i += ft_putnbr(n / 10) + ft_putnbr(n % 10);
	}
	return (i);
}
