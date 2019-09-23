/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:58:30 by viforget          #+#    #+#             */
/*   Updated: 2019/09/23 08:52:55 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int a;

	a = 123;
	//ft_printf("HEY: %sNBR = %li<3\n", "HEY ", 122153210615);
	//printf("HEY: %sNBR = %li<3\n", "HEY ", 122153210615);
	ft_printf("|%p|\n", &a);
	printf("|%p|\n", &a);
	return (0);
}
