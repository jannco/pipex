/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuncig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:23:07 by yadereve          #+#    #+#             */
/*   Updated: 2023/11/23 13:28:55 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuncig(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb < 10)
	{
		i += ft_putchar(nb + '0');
	}
	else
	{
		i += ft_putnbr(nb / 10) + ft_putnbr(nb % 10);
	}
	return (i);
}
