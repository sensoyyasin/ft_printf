/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:37:49 by ysensoy           #+#    #+#             */
/*   Updated: 2022/02/28 15:31:02 by ysensoy          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_basamak_sayisi(int c)
{
	int		i;

	i = 0;
	while (c > 0)
	{
		i++;
		c = c / 10;
	}
	return (i);
}

int	ft_uzunluk(unsigned long sayi)
{
	int	i;

	i = 0;
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

char	*hexfunc(unsigned long uzunluk, int key)
{
	char		*dizi;
	int			i;
	int			len;

	len = ft_uzunluk(uzunluk) + 1;
	dizi = (char *)malloc(sizeof(char) * len + 2);
	i = len;
	if (key == 2)
	{
	dizi[0] = '0';
	dizi[1] = 'x';
	key = 0;
	}
	while (uzunluk > 0 && len >= 2)
	{
		if (key == 1)
			dizi[len--] = buyuknumbers(uzunluk % 16);
		else
			dizi[len--] = numbers(uzunluk % 16);
		uzunluk = uzunluk / 16;
	}
	dizi[i] = '\0';
	return (dizi);
}

int	printing(va_list liste, char tip)
{
	if (tip == 'd' || tip == 'i')
		ft_putstr_fd(ft_itoa(va_arg(liste, int)), 1);
	else if (tip == 'c')
		ft_putchar_fd(va_arg(liste, int), 1);
	else if (tip == 's')
		ft_putstr_fd(va_arg(liste, char *), 1);
	else if (tip == 'p')
		ft_putstr_fd(hexfunc(va_arg(liste, unsigned long long), 2), 1);
	else if (tip == 'x')
		ft_putstr_fd(hexfunc(va_arg(liste, unsigned int), 0), 1);
	else if (tip == 'X')
		ft_putstr_fd(hexfunc(va_arg(liste, unsigned int), 0), 1);
	/*else if (tip == 'u')
	printf("%s",ft_uitoa(liste, unsigned int)); */
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list liste;
	int		i;
	int		arrivals;

	i = 0;
	arrivals = 0;
	va_start (liste, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			arrivals = printing(liste, str[i]);
		}
		i++;
	}
	va_end (liste);
	return (0);
}

int	main()
{
	char *a;
	char *s;

	a = "yasin";
	s = a;
	printf("%d\n",ft_printf("%p", &s));
	printf("%p", &s);
}
