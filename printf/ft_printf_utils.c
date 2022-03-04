/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:59:58 by ysensoy           #+#    #+#             */
/*   Updated: 2022/03/04 11:58:57 by ysensoy          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_basamak_sayisi(unsigned int c)
{
	int	i;

	i = 0;
	while (c > 0)
	{
		i++;
		c = c / 10;
	}
	return (i);
}

size_t	ft_uzunluk(size_t sayi)
{
	size_t	i;

	i = 0;
	if (sayi == 0)
		return (1);
	while (sayi > 0)
	{
		sayi = (sayi / 16);
		i++;
	}
	return (i);
}

char	numbers(int c)
{
	char	*d;

	d = "0123456789abcdef";
	return (d[c]);
}

char	buyuknumbers(int c)
{
	char	*s;

	s = "0123456789ABCDEF";
	return (s[c]);
}

size_t	ft_uitoa(unsigned int n)
{
	size_t		len;
	char		*str;
	size_t		i;

	len = ft_basamak_sayisi(n);
	i = len;
	str = (char *)malloc(sizeof(char) * len + 1);
	str[i] = '\0';
	if (n == 0)
	{
		free(str);
		return (write(1, "0", 1));
	}
	while (n > 0)
	{
		str[--len] = (n % 10) + 48;
		n = n / 10;
	}
	ft_putstr_fd(str, 1);
	free(str);
	return (i);
}
