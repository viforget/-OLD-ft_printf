/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:58:30 by viforget          #+#    #+#             */
/*   Updated: 2019/09/11 09:44:42 by viforget         ###   ########.fr       */
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

void			setfunctionnum(const char *st, int size)
{
	
}

void			setfunction(const char *st, void *var)
{
	if (*st == 'h')
	{
		st++;
		if (*st == 'h')
			return (setfunctionnum(st + 1, 2));
		return (setfunctionnum(st + 1, 1));

	}
	else if (*st == 'l')
	{
		st++;
		if (*st == 'l')
			return (setfunctionnum(st + 1, 32));
		return (setfunctionnum(st + 1, 64));
	}
	if (*st == 's')
		ft_putstr(*var);
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
