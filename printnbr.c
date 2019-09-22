/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 06:36:28 by viforget          #+#    #+#             */
/*   Updated: 2019/09/22 12:38:26 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		set1(char *str, int i, char c)
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

char	*parsing(char *st, int d, t_arg pars)
{
	char	*str;
	int		i;

	i = 0;
	if (d < pars.space)
	{
		if (pars.minus == 0)
			i = pars.space - d;
		d = pars.space;
	}
	else if (pars.plus != 0 || pars.neg != 0)
		i++;
	else if (pars.plus == 0)
		return (ft_strdup(st));
	pars.minus == 1 ? pars.zero = ' ' : 0;
	str = ft_memaset((sizeof(char)) * d, pars.zero);
	if (pars.neg == 1)
		pars.zero == '0' ? set1(str, 0, '-') : (i = set1(str, i, '-'));
	else if (pars.plus == 1)
		pars.zero == '0' ? set1(str, 0, '+') : (i = set1(str, i, '+'));
	else if (pars.plus == -1)
		pars.zero == '0' ? set1(str, 0, ' ') : (i = set1(str, i, ' '));
	while (*st)
		str[i++] = *st++;
	return (str);
}

void	printnbr2(char *fo, int d[2], unsigned long long n, t_arg arg)
{
	char	*stn;
	char	*str;

	if (!(stn = (char *)ft_memalloc(sizeof(char) * d[0] + 1)))
		return ;
	stn[d[0]] = 0;
	while (d[0] > 0)
	{
		stn[d[0] - 1] = fo[(n % d[1])];
		d[0]--;
		n /= d[1];
	}
	str = parsing (stn, ft_strlen(stn), arg);
	ft_putstrdel(str);
	ft_strdel(&stn);
}

void	printnbr(unsigned long long n, char *fo, int base, t_arg arg)
{
	unsigned long long	nb;
	int					d[2];

	d[0] = 0;
	d[1] = base;
	if (n == 0)
		return (ft_putchar('0'));
	nb = n;
	while (nb != 0)
	{
		d[0]++;
		nb /= d[1];
	}
	printnbr2(fo, d, n, arg);
}

/*int		main(int ac, char **argv)
{
	t_arg arg;

	if (ac >= 5)
	{
		arg.zero = argv[1][0];
		arg.plus = ft_atoi(argv[2]);
		arg.minus = ft_atoi(argv[3]);
		arg.space = ft_atoi(argv[4]);
		arg.neg = ft_atoi(argv[5]);
		ft_putchar('|');
		printnbr(123, "0123456789ABCDEF", 10, arg);
		//ft_putstr(parsing("123", 3, arg));
		ft_putchar('|');
		ft_putchar('\n');
	}
}*/
