/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setfunction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 08:52:04 by viforget          #+#    #+#             */
/*   Updated: 2019/11/13 14:56:50 by lhenneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

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
	if (c == 'f')
	{
		st = ft_float((long double)precision(va_arg(nbr, double), &arg), arg);
		ft_putstrdel(parsing(st, ft_strlen(st), arg)); //Penser a varier 6 en fonction du %. //DONE
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

int         set_precision(const char *st, t_arg *arg, int *pos)
{
    int     i;

    i = 1;
    st++;
    if (ft_isdigit((*st)))
        arg->precision = 0;
    while(*st && ft_isdigit(*st))
    {
        arg->precision = (arg->precision * 10) + (*st - '0');
        st++;
        i++;
    }
    *pos += i;
    return (i);
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
    if (*st == '.')
    {
        st += set_precision(st, &arg, &i);
    }
	if (*st == 's')
		ft_putstr(va_arg(ap, char *)); //THINK ABOUT THIS
	else if (*st == 'c')
		ft_putchar(va_arg(ap, int)); //THIS TOO
	else if (*st == 'p')
	{
		ft_putstr("0x"); //THIS AUSSI //WHEN TU START MIXING LES LANGUES IT'S TIME D'ALLER TO DODO
		printnbr(va_arg(ap, ull), "0123456789abcdef", 16, arg);
	}
	else
		setfunctionnum(ap, *st, UINT_MAX, arg);
	return (1 + i);
}
