/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinsensoy <yasinsensoy@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:37:49 by ysensoy           #+#    #+#             */
/*   Updated: 2022/03/08 13:47:36 by ysensoy          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_printer(unsigned long n)
{
	char	*a;

	a = ft_strdup("0123456789abcdef");
	if (n >= 16)
	{
		ptr_printer(n / 16);
		ptr_printer(n % 16);
	}
	else
		ft_putchars(a[n]);
	free(a);
	return (0);
}

int	ptr_print(unsigned long n)
{
	int	i;

	i = 1;
	ft_putchars('0');
	ft_putchars('x');
	ptr_printer(n);
	while (n >= 16)
	{
		n = n / 16;
		i++;
	}
	return (i + 2);
}

int	hexfunc(unsigned int sayi, char c)
{
	char			*str;
	int				len;
	char			*dizi;
	int				i;

	if (c == 'X')
		dizi = "0123456789ABCDEF";
	else
		dizi = "0123456789abcdef";
	len = ft_uzunluk(sayi);
	i = len;
	str = calloc(len, 1);
	if (sayi == 0)
		return (write(1, "0", 1));
	while (sayi > 0)
	{
		str[--i] = dizi[sayi % 16];
		sayi = sayi / 16;
	}
	ft_array(str);
	free(str);
	return (len);
}

int	printing(va_list liste, int tip)
{
	char	*a;
	int		i;

	i = 0;
	if (tip == 'c')
		i += ft_putchars(va_arg(liste, int));
	else if (tip == 'd' || tip == 'i')
	{
		a = ft_itoa(va_arg(liste, int));
		i += ft_array(a);
		free(a);
	}
	else if (tip == 's')
		i += ft_array(va_arg(liste, char *));
	else if (tip == 'p')
		i += ptr_print(va_arg(liste, unsigned long));
	else if (tip == 'x' || tip == 'X')
		i += hexfunc(va_arg(liste, unsigned int), tip);
	else if (tip == 'u')
		i += ft_uitoa(va_arg(liste, unsigned int));
	else if (tip == '%')
		i += ft_putchars('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	liste;
	int		i;
	int		len;

	va_start(liste, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += printing(liste, str[i]);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			len++;
		}
		i++;
	}
	va_end(liste);
	return (len);
}
/*
int	main()
{
	char *a;
	char *s;
	char *p;
	int	 x;

	x = 0;

	a = "yasin";
	s = a;
	x = ft_printf("%p\n", 1440);
	//printf("%p", s);
	//printf("%d\n",ft_printf("%u", 123));
	//printf("\n%u", 123);
	//printf("%d", x);
}
*/
