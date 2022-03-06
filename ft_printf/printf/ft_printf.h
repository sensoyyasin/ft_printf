/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinsensoy <yasinsensoy@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:37:27 by ysensoy           #+#    #+#             */
/*   Updated: 2022/03/06 21:19:30 by yasinsensoy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

char	numbers(int c);
char ft_yuzdebul(char *s);

int	ft_basamak_sayisi(unsigned int c);
int	ft_uzunluk(int sayi);
int	ft_putchars(char c);
int hexfunc(unsigned int sayi, char c);
int	printing(va_list liste, int tip);
int	ft_printf(const char *str, ...);
int	ft_uitoa(unsigned int n);
int	ft_array(char *str);
int	pointer_printer(unsigned long n);
int	pointer_print(unsigned long n);

#endif
