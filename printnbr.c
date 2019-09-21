/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 06:36:28 by viforget          #+#    #+#             */
/*   Updated: 2019/09/21 17:52:11 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int 	set1(char *str, int i, char c)
{
	if (i == 0)
	{
		str[0] = c;
		return (1);
	}
	else
		str[i - 1] = c;
	return (i);
}

char	*parsing(char *st, int d, t_arg pars, char free)
{
	char *str;
	int  i;
	
	i = 0;
	if (d < pars.space)
	{
		if (pars.minus == 0 /*|| pars.zero == '0'*/)
			i = pars.space - d ;
		d = pars.space;
	}
	else if (pars.plus != 0)
		i++;
	else if (pars.plus == 0)
		return (st);
	pars.minus == 1 ? pars.zero = ' ' : 0 ;
	str = ft_memaset((sizeof(char)) * d, pars.zero);
	if (pars.neg == 1)
		pars.zero == '0' ? set1(str, 0, '-') : (i = set1(str, i, '-'));
	else if (pars.plus == 1)
		pars.zero == '0' ? set1(str, 0, '+') + 1: (i = set1(str, i, '+'));
	else if (pars.plus == -1)
		pars.zero == '0' ? set1(str, 0, ' ') + 1: (i = set1(str, i, ' '));
	while(*st)
	{
		str[i] = *st;
		st++;
		i++;
	}
	free == 1 ? ft_strdel(&st) : 0;
	return (str);
}

void	printnbr2(char *st, int d, int base, unsigned long long n)
{
	char	*str;

	if (!(str = (char *)ft_memalloc(sizeof(char) * d + 1)))
		return ;
	str[d] = 0;
	while (d > 0)
	{
		str[d - 1] = st[(n % base)];
		d--;
		n /= base;
	}
	//str = parsing (str, arg, 1);
	ft_putstr(str);
	ft_strdel(&str);
}

void	printnbr(unsigned long long n, char *st, int base)
{
	unsigned long long	nb;
	int					d;

	d = 0;
	if (n == 0)
		return (ft_putchar('0'));
	nb = n;
	while (nb != 0)
	{
		d++;
		nb /= base;
	}
	printnbr2(st, d, base, n);
}

int		main(int ac, char **argv)
{
	t_arg arg;
	
	if (ac >= 5)
	{
		arg.zero = argv[1][0];
		arg.plus = ft_atoi(argv[2]);
		arg.minus = ft_atoi(argv[3]);
		arg.space = ft_atoi(argv[4]);
		arg.neg = ft_atoi(argv[5]);
		ft_putstr(parsing("123", 3, arg, 0));
		ft_putchar('|');
		ft_putchar('\n');
	}
}
