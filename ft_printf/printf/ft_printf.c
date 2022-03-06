/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinsensoy <yasinsensoy@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:37:49 by ysensoy           #+#    #+#             */
/*   Updated: 2022/03/06 20:59:26 by yasinsensoy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexfunc(unsigned int sayi, char c)
{
	int				i;
	int				i1;
	int				len;
	char			*dizi;
	unsigned int	n1;

	if (c == 'X')
		dizi = ft_strdup("0123456789ABCDEF");
	else
		dizi = ft_strdup("0123456789abcdef");
	i = 1;
	n1 = sayi;
	while (n1 >= 16 && i++)
		n1 = n1 / 16;
	len = i;
	while (--i >= 0)
	{
		n1 = len;
		i1 = i;
		while (--i1 >= 0)
			n1 = n1 / 16;
		ft_putchars(dizi[n1 % 16]);
	}
	free(dizi);
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
		i += pointer_print(va_arg(liste, unsigned long));
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

	a = "%zyasin";
	s = a;
	ft_printf("%u", -5);
	//printf("%d\n",ft_printf("%u", 123));
	//printf("\n%u", 123);
}
*/
