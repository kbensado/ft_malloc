/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyrigu <apeyrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 05:29:36 by apeyrigu          #+#    #+#             */
/*   Updated: 2017/02/23 06:51:42 by apeyrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_char(va_list ap, t_args *l)
{
	char c;

	c = (char)va_arg(ap, int);
	if (!(c))
	{
		if (l->size == 0 && (l->len = (l->len + 1)) != 0)
			return ;
		if (l->size == 2)
			l->len = l->len + 1;
		while (l->size != 1 && (l->len = (l->len + 1)) != 0)
		{
			write(1, " ", 1);
			l->size--;
		}
		return ;
	}
	l->ch[0] = c;
	l->ch[1] = '\0';
	l->width = 0;
	l->presci = 0;
	ft_size_max(l->ch, l);
}
