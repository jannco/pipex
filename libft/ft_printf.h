/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:42:25 by yadereve          #+#    #+#             */
/*   Updated: 2023/11/23 14:05:48 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

// # include <stddef.h>
// # include <stdlib.h>
// # include <string.h>
// # include <fcntl.h>
// # include <ctype.h>
// # include <limits.h>
// # include <stdio.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putpoint(void *address);
int		ft_putnbr(long int n);
int		ft_putuncig(unsigned int n);
int		ft_puthex(int nb, char c);
size_t	ft_strlen(const char *s);

#endif
