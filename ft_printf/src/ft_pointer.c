/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyrigu <apeyrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 05:09:24 by apeyrigu          #+#    #+#             */
/*   Updated: 2017/02/23 06:49:30 by apeyrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		ft_pointer(va_list ap, t_args *l)
{
	void	*p;
	char	buff[2][1024];

	ft_bzerof(&buff, 2048);
	p = va_arg(ap, void *);
	if (p == 0 && (l->size < 2 && l->width < 2))
	{
		l->presci == 1 ? print_char(l, 3, "0x") : print_char(l, 3, "0x0");
		return ;
	}
	l->z = 2;
	l->base[0] = 4;
	l->base[1] = 1;
	l->hastag = 1;
	l->unb = (long)p;
	convert_base(l, buff);
	if (l->less == 1)
		while (l->padding[0] > 0)
			l->zero == 1 ? print_char(l, 0, "0") : print_char(l, 0, " ");
}
