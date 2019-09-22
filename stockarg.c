/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stockarg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 11:17:29 by viforget          #+#    #+#             */
/*   Updated: 2019/09/22 14:40:36 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_arg	arginit()
{
	t_arg arg;

	arg.zero = ' ';
	arg.minus = 0;
	arg.plus = 0;
	arg.neg = 0; //NOT SURE //NAN C'EST BON JE SUIS SUR MAINTENANT
	arg.space = 0;
	return (arg);
}

int		stockarg(t_arg *arg, char const *fo)
{
	int	i;

	i = 0;
	*arg = arginit();
	while(fo[i])
	{
		if (fo[i] == '0')
			arg->zero = '0';
		else if (fo[i] == '-')
			arg->minus = 1;
		else if (fo[i] == '+')
			arg->plus = 1;
		else if (fo[i] == ' ' && arg->plus == 0)
			arg->plus = -1;
		else if (fo[i] >= '1' && fo[i] <= '9')
		{
			arg->space = ft_atoi(fo + i);
			while(fo[i + 1] >= '1' && fo[i + 1] <= '9')
				i++;
		}
		else
			return (i);
		i++;
	}
	return (i);
}
