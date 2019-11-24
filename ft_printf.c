/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:58:30 by viforget          #+#    #+#             */
/*   Updated: 2019/11/13 15:07:54 by lhenneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

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
	ft_printf("|%f|\n", 42.5);
    printf("|%.1f|\n", 42.5);

    ft_printf("|%f|\n", 3.1415354);
    printf("|%.1f|\n", 3.1415354);
   /*
    test::sprintf(buffer, "%.4f", 3.1415354);
    REQUIRE(!strcmp(buffer, "3.1415"));

    test::sprintf(buffer, "%.3f", 30343.1415354);
    REQUIRE(!strcmp(buffer, "30343.142"));

    test::sprintf(buffer, "%.0f", 34.1415354);
    REQUIRE(!strcmp(buffer, "34"));

    test::sprintf(buffer, "%.0f", 1.3);
    REQUIRE(!strcmp(buffer, "1"));

    test::sprintf(buffer, "%.0f", 1.55);
    REQUIRE(!strcmp(buffer, "2"));

    test::sprintf(buffer, "%.1f", 1.64);
    REQUIRE(!strcmp(buffer, "1.6"));

    test::sprintf(buffer, "%.2f", 42.8952);
    REQUIRE(!strcmp(buffer, "42.90"));

    test::sprintf(buffer, "%.9f", 42.8952);
    REQUIRE(!strcmp(buffer, "42.895200000"));

    test::sprintf(buffer, "%.10f", 42.895223);
    REQUIRE(!strcmp(buffer, "42.8952230000"));

    // this testcase checks, that the precision is truncated to 9 digits.
    // a perfect working float should return the whole number
    test::sprintf(buffer, "%.12f", 42.89522312345678);
    REQUIRE(!strcmp(buffer, "42.895223123000"));

    // this testcase checks, that the precision is truncated AND rounded to 9 digits.
    // a perfect working float should return the whole number
    test::sprintf(buffer, "%.12f", 42.89522387654321);
    REQUIRE(!strcmp(buffer, "42.895223877000"));

    test::sprintf(buffer, "%6.2f", 42.8952);
    REQUIRE(!strcmp(buffer, " 42.90"));

    test::sprintf(buffer, "%+6.2f", 42.8952);
    REQUIRE(!strcmp(buffer, "+42.90"));

    test::sprintf(buffer, "%+5.1f", 42.9252);
    REQUIRE(!strcmp(buffer, "+42.9"));

    test::sprintf(buffer, "%f", 42.5);
    REQUIRE(!strcmp(buffer, "42.500000"));

    test::sprintf(buffer, "%.1f", 42.5);
    REQUIRE(!strcmp(buffer, "42.5"));

    test::sprintf(buffer, "%f", 42167.0);
    REQUIRE(!strcmp(buffer, "42167.000000"));

    test::sprintf(buffer, "%.9f", -12345.987654321);
    REQUIRE(!strcmp(buffer, "-12345.987654321"));

    test::sprintf(buffer, "%.1f", 3.999);
    REQUIRE(!strcmp(buffer, "4.0"));

    test::sprintf(buffer, "%.0f", 3.5);
    REQUIRE(!strcmp(buffer, "4"));

    test::sprintf(buffer, "%.0f", 4.5);
    REQUIRE(!strcmp(buffer, "4"));

    test::sprintf(buffer, "%.0f", 3.49);
    REQUIRE(!strcmp(buffer, "3"));

    test::sprintf(buffer, "%.1f", 3.49);
    REQUIRE(!strcmp(buffer, "3.5"));

    test::sprintf(buffer, "a%-5.1f", 0.5);
    REQUIRE(!strcmp(buffer, "a0.5  "));*/

    return (0);
}
