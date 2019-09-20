/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:14:25 by viforget          #+#    #+#             */
/*   Updated: 2019/09/20 08:15:45 by viforget         ###   ########.fr       */
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
**	PRINTNBR.C
*/

void	printnbr(unsigned long long n, char *st, int base);

/*
** STRUCTURE
*/

typedef	struct	s_pars
{
	char		zero;
	char		plus;
	int 		space;
}				t_pars;

/*
**	GLOBAL
*/

t_pars			*g_pars;

#endif
