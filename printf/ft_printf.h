/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:37:27 by ysensoy           #+#    #+#             */
/*   Updated: 2022/02/28 15:11:32 by ysensoy          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_basamak_sayisi(int c);
int	ft_uzunluk(unsigned long sayi);
char	numbers(int c);
char *hexfunc(unsigned long uzunluk, int key);
int	printing(va_list liste, char tip);
int	ft_printf(const char *str, ...);

#endif
