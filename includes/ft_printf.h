/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:14:25 by viforget          #+#    #+#             */
/*   Updated: 2019/11/13 15:11:15 by lhenneca         ###   ########.fr       */
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
    int 		width;
    int         precision;
    char        *str;
}				t_arg;

/*
**	PRINTNBR.C
*/

char	*parsing(char *st, int d, t_arg pars);
void	printnbr(unsigned long long n, char *st, int base, t_arg arg);


/*
** STOCKARG.C
*/

int		stockarg(t_arg *arg, char const *fo);

/*
** SETFUNCTION.C
*/

int		setfunction(const char *st, va_list ap);

/*
** FT_FLOAT.C
*/

long double	precision(double f, int p);
char	*ft_float(long double f, t_arg arg);

#endif
