/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memaset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 07:16:44 by viforget          #+#    #+#             */
/*   Updated: 2019/09/20 07:16:48 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memaset(size_t size, char c)
{
	void *mem;

	mem = malloc(size);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, c, size);
	return (mem);
}
