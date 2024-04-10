/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:09:26 by yadereve          #+#    #+#             */
/*   Updated: 2023/11/23 13:38:47 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checkformat(char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'u')
		return (ft_putuncig(va_arg(ap, unsigned int)));
	else if (c == 'p')
		return (ft_putpoint(va_arg(ap, void *)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(ap, int), c));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		n;

	va_start(ap, format);
	i = 0;
	n = 0;
	while (format[i])
	{
		if (format[i] == '%')
			n += ft_checkformat(format[++i], ap);
		else
			n += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (n);
}
