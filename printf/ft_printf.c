/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:37:49 by ysensoy           #+#    #+#             */
/*   Updated: 2022/03/04 13:38:14 by ysensoy          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hexfunc(unsigned long sayi, int key)
{
	char		*dizi;
	int			len;

	if (key == 2)
	{
		len = ft_uzunluk(sayi) + 3;
		dizi = (char *)malloc(len--);
		dizi[len--] = '\0';
		dizi[0] = '0';
		dizi[1] = 'x';
		key = 0;
	}
	else
	{
		len = ft_uzunluk(sayi) + 1;
		dizi = (char *)malloc(len--);
		dizi[len--] = '\0';
	}
	while (sayi >= 16)
	{
		if (key == 0)
			dizi[len] = numbers(sayi % 16);
		else
			dizi[len] = buyuknumbers(sayi % 16);
		sayi = sayi / 16;
		len--;
	}
	if (key == 0)
		dizi[len] = numbers(sayi % 16);
	else
		dizi[len] = buyuknumbers(sayi % 16);
	return (dizi);
}

size_t	printing(va_list liste, char tip)
{
	char	*a;
	size_t	b;
	int		i;
	
	a = NULL;
	i = 0;
	b = 0;
	if (tip == 'd' || tip == 'i')
		a = ft_itoa(va_arg(liste, int));
	else if (tip == 'c')
	{
		ft_putchar_fd(va_arg(liste, int), 1);
		return (1);
	}
	else if (tip == 's')
	{
		a = va_arg(liste, char *);
		if (a == NULL)
		{
			ft_putstr_fd("(null)" , 1);
			return (6);
		}
		i = 1;
	}
	else if (tip == 'p')
		a = hexfunc(va_arg(liste, unsigned long long), 2);
	else if (tip == 'x')
		a = hexfunc(va_arg(liste, unsigned int), 0);
	else if (tip == 'X')
		a = hexfunc(va_arg(liste, unsigned int), 1);
	else if (tip == 'u')
		return (ft_uitoa(va_arg(liste, unsigned int)));
	else 
	{
		return (write(1, &tip, 1));
	}
	ft_putstr_fd(a, 1);
	b = ft_strlen(a);
	if (i == 0)
		free(a);
	return (b);
}

int	ft_printf(const char *str, ...)
{
	va_list	liste;
	int		i;
	size_t	arrivals;

	i = 0;
	arrivals = 0;
	va_start (liste, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			arrivals += printing(liste, str[i]);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			arrivals++;
		}
		i++;
	}
	va_end (liste);
	return (arrivals);
}
/*
int	main()
{
	char *a;
	char *s;
	char *p;

	a = "%zyasin";
	s = a;
	ft_printf("%u", -5);
	//printf("%d\n",ft_printf("%u", 123));
	//printf("\n%u", 123);
}
*/
