/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:36:53 by lhenneca          #+#    #+#             */
/*   Updated: 2019/11/13 15:13:38 by lhenneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "includes/ft_printf.h"
#include "libft/libft.h"

int		exponent(int n, int e)
{
	int		i;

	i = n;
	while(e > 1)
	{
		n *= i;
		e--;
	}
	return (n);
}

long double	precision(double f, t_arg *arg)
{
	int i;
	int p;

	p = arg->precision;
	f < 0 ? ((arg->neg = 1) && (f *= -1)) : 0;
	i = f * exponent(10,p + 1);
	if (i % 10 > 5 || (((i % 10) == 5) && (((i / 10) % 10) % 2 == 1) ))
		p > 0 ? (f += 1.0 / exponent(10,p)) : (f += 1);
	return (f);
}

int		ft_nbrlen(int nbr)
{
	int		i;
	int		len;

	i = 10;
	len = 1;
	while ((nbr /= 10) > 0)
		len++;
	return (len);
}

char    *ft_nan()
{
    return ("nan");
}

char	*ft_float(long double f, t_arg arg)
{
	int		nb;
	int		size;
	int		i;

	if (f != f)
        return (ft_nan());
    if (f )
	size = ft_nbrlen((int)f) + arg.precision + 2;
	arg.str = ft_memalloc(size * sizeof(char));
	nb = (int)f;
	f -= nb;
	f *= exponent(10,arg.precision);
	i = 0;
	size--;
	while (i < arg.precision)
	{
		size--;
		i++;
		arg.str[size] = '0' + (int)f % 10;
		f /=10;
	}
	size--;
	if (arg.precision > 0)
	    arg.str[size] = '.';
	nb == 0 ? arg.str[size - 1] = '0' : 0;
	while (nb > 0)
	{
		size--;
		arg.str[size] = '0' + nb % 10;
		nb /=10;
	}
	return (arg.str);
}

/*
int		main(void)
{
	float	f = 99;
	char	*str = ft_float(precision((long double)f,2),20);
	printf("printf %.20f\n",f);
	printf("mine   %s", str);
}
	//printf("\nHere %d\n", size);
*/
