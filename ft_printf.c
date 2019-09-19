/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:58:30 by viforget          #+#    #+#             */
/*   Updated: 2019/09/19 09:52:53 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <limits.h>
#include <math.h>
#include <stdio.h>

unsigned int	cnt_percent(const char *format)
{
	unsigned int	p;

	p = 0;
	while(*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format != '%')
				p++;
			else
				format++;
		}
		else 
			format++;
	}
	return (p);
}

void			setfunctionnum(long long nbr, char c, unsigned long long size)
{
	char *st;
	int base;
	int nb;

	size++;
	base = 2;
	st = "0123456789abcdef";
	if (c <= 'Z')
	{
		c += 32;
		st = "0123456789ABCDEF";
	}
	while ((BASE[base] != c && base <= 16) || BASE[base] == '.')
		base++;
	if (base <= 16)
	{
		printnbr((ull)nbr % size, st, base);
	}
	else if (c == 'd' || c == 'i')
	{
		
		nb = ((int)nbr + INT_MAX + 1) % UINT_MAX - INT_MAX - 1;
		if (nb < 0)
		{
			if (nb == INT_MIN)
				return(ft_putstr("-2147483648"));
			ft_putchar('-');
			nb = nb * -1;
		}
		printnbr(nb, "0123456789", 10);
	}		
}

void			setfunction(const char *st, va_list  ap)
{
	if (*st == 'h')
	{
		st++;
		if (*st == 'h')
			return (setfunctionnum(va_arg(ap, long long), st[1], UCHAR_MAX));
		return (setfunctionnum(va_arg(ap, long long) ,st[1], USHRT_MAX));

	}
	else if (*st == 'l')
	{
		st++;
		if (*st == 'l')
			return (setfunctionnum(va_arg(ap, long long), st[1], ULONG_MAX));
		return (setfunctionnum(va_arg(ap, long long), st[1], ULLONG_MAX));
	}
	else if (*st == 's')
		ft_putstr(va_arg(ap, char *));
	else if (*st == 'c')
		ft_putchar(va_arg(ap, int));
	setfunctionnum(va_arg(ap, long long), *st, UINT_MAX);
}

int				ft_printf(const char *format, ...)
{
	va_list			ap;
	unsigned int	p;
	unsigned int	s;
	unsigned int	e;

	s = 0;
	e = 0;
	p = cnt_percent(format);
	va_start(ap, format);
	while(format[e] != '\0')
	{
		if (format[e] == '%')
		{
			write(1, format + s, e - s);
			setfunction(format + e + 1, ap);
			e += 2;
			s = e;
		}
		e++;
	}
	write(1, format + s, e - s);
	va_end(ap);
	return(0);
}

int 			main()
{
	//setfunction("dsdf", 2147483648);
	//printf("\n%d\n", INT_MAX + 1);
	ft_printf("HEY %s\nSAL%lli\nUT\n", "HEY ",12215321061532);	
	return (0);
}
