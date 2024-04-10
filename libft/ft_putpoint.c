/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:50:24 by yadereve          #+#    #+#             */
/*   Updated: 2023/11/23 13:28:44 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthexaddress(uintptr_t n)
{
	int				i;

	i = 0;
	if (n >= 16)
	{
		i += ft_puthexaddress(n / 16);
		i += ft_puthexaddress(n % 16);
	}
	else
	{
		i += ft_putchar("0123456789abcdef"[n]);
	}
	return (i);
}

int	ft_putpoint(void *address)
{
	int	i;

	i = 0;
	if (!address)
	{
		i += ft_putstr("(nil)");
		return (i);
	}
	else
	{
		write(1, "0x", 2);
		i += ft_puthexaddress((uintptr_t)address);
	}
	return (i + 2);
}
