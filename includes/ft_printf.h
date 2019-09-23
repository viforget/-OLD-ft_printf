/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:14:25 by viforget          #+#    #+#             */
/*   Updated: 2019/09/23 08:58:40 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
**	INCLUDE
*/

# include "../libft/libft.h"
# include <stdarg.h>
# include <limits.h>

/*
** DEFINE
*/

# define BASE "..b.....o.u.....x"
# define ull unsigned long long

/*
** STRUCTURE
*/

typedef	struct	s_arg
{
	char		zero;
	char		minus;
	char		plus;
	char		neg;
	int 		space;
}				t_arg;

/*
**	PRINTNBR.C
*/

void	printnbr(unsigned long long n, char *st, int base, t_arg arg);


/*
** STOCKARG.C
*/

int		stockarg(t_arg *arg, char const *fo);

/*
** SETFUNCTION.C
*/

int		setfunction(const char *st, va_list ap);

#endif
