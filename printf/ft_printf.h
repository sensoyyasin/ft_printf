/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:37:27 by ysensoy           #+#    #+#             */
/*   Updated: 2022/03/04 11:26:29 by ysensoy          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

//#ifndef FT_PRINTF_H
//# define FT_PRINTF_H

# include "libft/libft.h"
//# include "./ft_printf_utils.c"
# include <stdarg.h>

size_t	ft_basamak_sayisi(unsigned int c);
size_t	ft_uzunluk(unsigned long sayi);
char	numbers(int c);
char *hexfunc(unsigned long uzunluk, int key);
int	ft_printf(const char *str, ...);
size_t	ft_uitoa(unsigned int n);
char buyuknumbers(int c);
char ft_yuzdebul(char *s);

//#endif
