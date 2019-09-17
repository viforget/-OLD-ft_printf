/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:58:30 by viforget          #+#    #+#             */
/*   Updated: 2019/09/13 15:39:41 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

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

void			setfunctionnum(void *nbr, char c, unsigned int size)
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
		printnbr((ull)nbr, st, base);
	else if (c == 'd' || c == 'i')
	{
		nb = (int)nbr;
		if ((int)nbr < 0)
		{
			ft_putchar('-');
			nb = nb * -1;
		}
		printnbr(nb, "0123456789", 10);
	}		
}

void			setfunction(const char *st, void *var /*, char *bs*/)
{
	if (*st == 'h')
	{
		st++;
		if (*st == 'h')
			return (setfunctionnum(var, st[1], 1));
		return (setfunctionnum(var ,st[1], 2));

	}
	else if (*st == 'l')
	{
		st++;
		if (*st == 'l')
			return (setfunctionnum(var, st[1], 4));
		return (setfunctionnum(var, st[1], 5));
	}
	else if (*st == 's')
		ft_putstr(var);
	else if (*st == 'c')
		ft_putchar((char)var);
	setfunctionnum(var, *st, 0);
}

/*int				ft_printf(const char *format, ...)
{
	va_list			ap;
	unsigned int	p;
	unsigned int	s;
	unsigned int	e;

	s = 0;
	e = 0;
	p = cnt_percent(format);
	while(format[e] != '\0')
	{
		if (format[e] == '%')
		{
			write(1, format + s, e - s);
			setfunction(format + e + 1);
			e += 2;
			s = e;
		}
		e++;
	}
	write(1, format + s, e - s);
	return(0);
}*/

int 			main()
{
	setfunction("xsdf", (void *)123);
	//ft_printf("HEY %dSAL%iUT\n");	
	return (0);
}
