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

long double	precision(double f, int p)
{
	int i;

	i = f * exponent(10,p + 1);
	if (i % 10 > 5)
		f += 1.0 / exponent(10,p + 1);
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

char	*ft_float(long double f, int maxF)
{
	char	*period;
	int		nb;
	int		size;
	int		i;

	size = ft_nbrlen((int)f) + maxF + 2;
	period = malloc(size * sizeof(char));
	nb = (int)f;
	f -= nb;
	f *= exponent(10,maxF);
	i = 0;
	size--;
	period[size] = '\0';
	while (i < maxF)
	{
		size--;
		i++;
		period[size] = '0' + (int)f % 10;
		f /=10;
	}
	size--;
	period[size] = '.';
	while (nb > 0)
	{
		size--;
		period[size] = '0' + nb % 10;
		nb /=10;
	}
	return (period);
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
