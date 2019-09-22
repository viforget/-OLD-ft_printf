/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:58:30 by viforget          #+#    #+#             */
/*   Updated: 2019/09/22 14:42:06 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

unsigned int	cnt_percent(const char *format)
{
	unsigned int	p;

	p = 0;
	while (*format != '\0')
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

void			setfunctionnum(va_list nbr, char c, unsigned long long size, t_arg arg)
{
	char		*st;
	int			base;
	long long	nb;

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
		printnbr(va_arg(nbr, ull) % size, st, base, arg);
	}
	else if (c == 'd' || c == 'i')
	{
		nb = (va_arg(nbr, ull) + size / 2 + 1) % size - (size / 2) - 1;
		if (nb < 0)
		{
			if (nb == INT_MIN)
				return (ft_putstr("-2147483648"));
			arg.neg = 1;
			nb = nb * -1;
		}
		printnbr(nb, "0123456789", 10, arg);
	}
}

int			setfunction(const char *st, va_list ap)
{
	t_arg 	arg;
	int 	i;

	i = stockarg(&arg, st);
	st += i;
	if (*st == 'h')
	{
		st++;
		if (*st == 'h')
		{
			setfunctionnum(ap, st[1], UCHAR_MAX, arg);
			return (3 + i);
		}
		setfunctionnum(ap, st[0], USHRT_MAX, arg);
		return (2 + i);
	}
	else if (*st == 'l')
	{
		st++;
		if (*st == 'l')
		{
			setfunctionnum(ap, st[1], ULLONG_MAX, arg);
			return (3 + i);
		}
		setfunctionnum(ap, st[0], ULONG_MAX, arg);
		return (2 + i);
	}
	else if (*st == 's')
		ft_putstr(va_arg(ap, char *)); //THINK ABOUT THIS
	else if (*st == 'c')
		ft_putchar(va_arg(ap, int)); //THIS TOO
	else
		setfunctionnum(ap, *st, UINT_MAX, arg);
	return (1 + i);
}

int				ft_printf(const char *format, ...)
{
	va_list			ap;
	unsigned int	s;
	unsigned int	e;

	s = 0;
	e = 0;
	va_start(ap, format);
	while (format[e] != '\0')
	{
		if (format[e] == '%')
		{
			write(1, format + s, e - s);
			e += setfunction(format + e + 1, ap) + 1;
			s = e;
		}
		e++;
	}
	write(1, format + s, e - s);
	va_end(ap);
	return (0);
}

#include <stdio.h>

int				main(void)
{
	ft_printf("HEY: %sNBR = %li<3\n", "HEY ", 122153210615);
	printf("HEY: %sNBR = %li<3\n", "HEY ", 122153210615);
	//ft_printf("|%+5-d|\n", 123);
	return (0);
}
