/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:36:31 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/23 14:08:04 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		add_one(t_args *l, int i)
{
	if (i < 0)
		return ;
	if (l->x.res_f[i] == '9')
	{
		l->x.res_f[i] = '0';
		add_one(l, i - 1);
	}
	else
		l->x.res_f[i]++;
}

void			round_point(t_args *l, int i)
{
	i = ft_strlenf(FLOAT.res_f) - 1;
	if (FLOAT.res_f[i] >= '5')
	{
		FLOAT.res_f[i] = '.';
		add_one(l, i - 1);
	}
	if (l->hastag)
		FLOAT.res_f[i++] = '.';
	FLOAT.res_f[i] = 0;
}

void			zero_except(t_args *l)
{
	if (l->size > 0 && l->width > 0)
		print_char(l, 3, "0");
	else if (l->size > 0 && !l->length && !l->width)
		print_char(l, 3, "");
	else if (l->size == 0)
		print_char(l, 3, "");
	else
		print_char(l, 3, " ");
}

int				ft_is_digitf(int c)
{
	if (c >= '0' || c <= '9')
		return (1);
	return (0);
}

void			res_except(t_args *l, char buff[], int tmp)
{
	set_pre_lar_hex(l, 1);
	while (-1 != tmp)
	{
		write(1, &buff[tmp], 1);
		l->len = l->len + 1;
		tmp--;
	}
}
