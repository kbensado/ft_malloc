/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 22:47:13 by kbensado          #+#    #+#             */
/*   Updated: 2017/02/25 02:15:58 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void			set_pre_lar_1(t_args *l, uint64_t nb)
{
	l->sfm = the_stronger(l, nb);
	while (l->padding[0] > 0 && l->less == 0)
		l->zero == 1 ? print_char(l, 0, "0") : print_char(l, 0, " ");
	while (l->padding[1] > 0)
		print_char(l, 1, "0");
}

void				ft_print_ulong(uint64_t i, t_args *l, int key)
{
	if (key == 0)
	{
		l->length = get_nblen(i);
		set_pre_lar_1(l, i);
		if (i == 0 && l->presci == 1)
			return ;
	}
	if (i >= 10)
		ft_print_long((i / 10), l, 1);
	ft_putchar_fdf(((i % 10) + '0'), l->fd);
	l->len = l->len + 1;
}
