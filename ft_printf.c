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
    ft_printf("|%.1f|\n", 42.5);
    printf("|%.1f|\n", 42.5);

    ft_printf("|%04.1f|\n", -3.1415354);
    printf("|%04.1f|\n", -3.1415354);

    ft_printf("|%04d|\n",-42);
    printf("|%04d|\n", -42);

    ft_printf("|%.4f|\n", 3.1415354);
    printf("|%.4f|\n", 3.1415354);

    ft_printf("|%.3f|\n", 30343.1415354);
    printf("|%.3f|\n", 30343.1415354);

    ft_printf("|%.0f|\n", 34.1415354);
    printf("|%.0f|\n", 34.1415354);

    ft_printf("|%.0f|\n", 1.3);
    printf("|%.0f|\n", 1.3);

    ft_printf("|%.0f|\n", 1.55);
    printf("|%.0f|\n", 1.55);

    ft_printf("|%.1f|\n", 1.64);
    printf("|%.1f|\n", 1.64);

    ft_printf("|%.2f|\n", 42.8952);
    printf("|%.2f|\n", 42.8952);

    ft_printf("|%.9f|\n", 42.8952);
    printf("|%.9f|\n", 42.8952);

    ft_printf("|%.10f|\n", 42.895223);
    printf("|%.10f|\n", 42.895223);

    ft_printf("|%.12f|\n", 42.89522312345678);
    printf("|%.12f|\n", 42.89522312345678);

    ft_printf("|%.12f|\n", 42.89522387654321);
    printf("|%.12f|\n", 42.89522387654321);

    ft_printf("|%6.2f|\n", 42.8952);
    printf("|%6.2f|\n", 42.8952);

    ft_printf("|%+6.2f|\n", 42.8952);
    printf("|%+6.2f|\n", 42.8952);

    ft_printf("|%+5.1f|\n", 42.9252);
    printf("|%+5.1f|\n", 42.9252);

    ft_printf("|%f|\n", 42.5);
    printf("|%f|\n", 42.5);

    ft_printf("|%.1f|\n", 42.5);
    printf("|%.1f|\n", 42.5);

    ft_printf("|%f|\n", 42167.0);
    printf("|%f|\n", 42167.0);

    ft_printf("|%.9f|\n", -12345.987654321);
    printf("|%.9f|\n", -12345.987654321);

    ft_printf("|%.1f|\n", 3.999);
    printf("|%.1f|\n", 3.999);

    ft_printf("|%.0f|\n", 3.5);
    printf("|%.0f|\n", 3.5);

    ft_printf("|%.0f|\n", 4.5);
    printf("|%.0f|\n", 4.5);

    ft_printf("|%.0f|\n", 3.49);
    printf("|%.0f|\n", 3.49);

    ft_printf("|%.1f|\n", 3.49);
    printf("|%.1f|\n", 3.49);

    ft_printf("a|%-5.1f|\n", 0.5);
    printf("a|%-5.1f|\n", 0.5);

    return (0);
}
