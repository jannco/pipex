/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:48:41 by yadereve          #+#    #+#             */
/*   Updated: 2023/11/23 13:28:32 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(int nb, char c)
{
	int				i;
	unsigned int	x;

	x = nb;
	i = 0;
	if (x >= 16)
	{
		i += ft_puthex(x / 16, c);
		i += ft_puthex(x % 16, c);
	}
	else
	{
		if (c == 'x')
			i += ft_putchar("0123456789abcdef"[x]);
		else if (c == 'X')
			i += ft_putchar("0123456789ABCDEF"[x]);
	}
	return (i);
}
