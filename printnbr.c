/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 06:36:28 by viforget          #+#    #+#             */
/*   Updated: 2019/09/20 06:38:28 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	printnbr2(char *st, int d, int base, unsigned long long n)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * d + 1)))
		return ;
	str[d] = 0;
	while (d > 0)
	{
		str[d - 1] = st[(n % base)];
		d--;
		n /= base;
	}
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
