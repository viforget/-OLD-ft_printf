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

void			*unitfunct(void	*(*f)(void *, char *, unsigned int))
{
	f = malloc(sizeof(*f) * 6);
	f[1] = printushortshort(short short, char *, unsigned int);
	f[2] = printushort(short, char *, unsigned int);
	f[4] = printulonglong(long long, char *, unsigned int);
	f[5] = printulong(long, char *, unsigned int);
	return (f);
}

void			setfunctionnum(const char *st, unsigned int size)
{
	void *(*f)(void *, char *, unsigned int);

	f = unitfunct(f);
}

void			setfunction(const char *st, void *var, char *bs)
{
	if (*st == 'h')
	{
		st++;
		if (*st == 'h')
			return (setfunctionnum(st + 1, 1));
		return (setfunctionnum(st + 1, 2));

	}
	else if (*st == 'l')
	{
		st++;
		if (*st == 'l')
			return (setfunctionnum(st + 1, 4));
		return (setfunctionnum(st + 1, 5));
	}
	else if (*st == 's')
		ft_putstr(*var);
	else if (*st == 'c')
		ft_putchar(*var);
	setfunctionnum(st, 0);
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
}

int 			main()
{
	ft_printf("HEY %dSAL%iUT\n");	
	return (0);
}
