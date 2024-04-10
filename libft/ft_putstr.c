/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:22:51 by yadereve          #+#    #+#             */
/*   Updated: 2023/11/23 13:28:49 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	len;
	int	i;

	if (!s)
		return (ft_putstr("(null)"));
	len = 0;
	i = 0;
	while (s[i])
	{
		len += ft_putchar(s[i]);
		i++;
	}
	return (len);
}
