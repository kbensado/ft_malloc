/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 07:59:17 by apeyrigu          #+#    #+#             */
/*   Updated: 2017/03/14 04:04:43 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void				print_res(char buff[1024], t_args *l, int len)
{
	int				tmp;

	tmp = len - 1;
	while (buff[tmp] == '0')
		tmp--;
	l->length = tmp + 1;
	if (tmp < 0)
	{
		l->length = 1;
		set_pre_lar_hex(l, 0);
		if (l->presci == 1 && l->length == 1)
		{
			if (l->presci == 1 && l->unb == 0 && l->size > 1)
			{
				print_char(l, 3, " ");
				return ;
			}
			(l->flags[l->flag] == 'p' && l->width > 1) || (l->hastag == 1
			&& l->base[0] == 3) ? print_char(l, 3, "0") : print_char(l, 3, "");
		}
		else
			print_char(l, 3, "0");
		return ;
	}
	res_except(l, buff, tmp);
}

void				do_padding_z(t_args *l, int64_t nb)
{
	if (l->hastag == 1 && l->zero == 1)
	{
		(void)nb;
		l->base[1] == 1 ? print_char(l, 3, "0x") : print_char(l, 3, "0X");
		l->hastag--;
		return ;
	}
	l->zero == 1 ? print_char(l, 0, "0") : print_char(l, 0, " ");
}

void				convert_option(t_args *l)
{
	if (ft_strchrf(l->flags, 'x'))
	{
		l->base[0] = 4;
		l->base[1] = 1;
	}
	if (ft_strchrf(l->flags, 'X'))
	{
		l->base[0] = 4;
		l->base[1] = 0;
	}
	if (ft_strchrf(l->flags, 'o'))
	{
		l->base[0] = 3;
		l->base[1] = 1;
	}
	if (ft_strchrf(l->flags, 'O'))
	{
		l->base[0] = 3;
		l->base[1] = 0;
	}
	if (ft_strchrf(l->flags, 'b'))
	{
		l->base[0] = 1;
		l->base[1] = 0;
	}
}

void				set_pre_lar_hex(t_args *l, int key)
{
	l->sfm = the_stronger_hexa(l);
	if (l->padding[0] > 0 && l->hastag == 1)
	{
		if (l->base[0] == 4)
			l->padding[0] = l->padding[0] - 2;
		if (l->base[0] == 3)
			l->padding[0]--;
	}
	while (l->padding[0] > 0 && l->less == 0)
		do_padding_z(l, key);
	if (l->hastag == 1 && l->base[0] == 4)
	{
		if (key == 0 && l->flags[l->flag] != 'p')
			return ;
		l->base[1] == 1 ? print_char(l, 3, "0x") : print_char(l, 3, "0X");
	}
	if (l->hastag == 1 && l->base[0] == 3 && l->width < l->length && key != 0)
		print_char(l, 2, "0");
	while (l->padding[1] > 0)
		print_char(l, 1, "0");
}
