/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 03:32:21 by apeyrigu          #+#    #+#             */
/*   Updated: 2017/03/14 03:56:58 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

long long			ft_llabs(long long j)
{
	return (j < 0 ? -j : j);
}

/*
** lance le shifumi entre la taille reel de nb la precision et la largeur
** len > precision > largeur || if even the left solution is stronger.
** si on l'enleve les conversion sans precision et largeur marchent.
*/

static void			pre_padding(t_args *l, int key, int64_t nb)
{
	if (key == 0)
	{
		if (nb >= 0 && l->plus == 1)
			print_char(l, 0, "+");
		if (nb < 0 && (l->zero == 1 || l->less == 1))
		{
			print_char(l, 3, "-");
			l->sfm = 1;
		}
	}
	else
	{
		if (nb > 0 && l->plus == 1)
			print_char(l, 0, "+");
		if (nb < 0 && ((l->zero == 1 || l->less == 1)
			|| l->sfm == 1 || l->padding[1] > 0))
		{
			print_char(l, 0, "-");
			l->sfm = 1;
		}
	}
	l->plus = 0;
}

void				set_pre_lar(t_args *l, int64_t nb)
{
	l->sfm = the_stronger(l, nb);
	if (l->padding[0] > 0 && l->padding[1] > 0)
		l->zero = 0;
	nb < 0 ? l->padding[0]-- : (void)l;
	if (l->espace && nb >= 0)
		print_char(l, 0, " ");
	if (l->padding[0] > 0 && l->padding[1] < 1)
		pre_padding(l, 0, nb);
	while (l->padding[0] > 0 && l->less == 0)
		l->zero == 1 ? print_char(l, 0, "0") : print_char(l, 0, " ");
	if (l->padding[1] > 0)
		pre_padding(l, 1, nb);
	while (l->padding[1] > 0)
		print_char(l, 1, "0");
}

void				force_print_long(int64_t nb, t_args *l)
{
	char	buff[BUFF_SIZE];
	int		i;
	int		n;
	int		s;

	i = 0;
	n = (nb < 0);
	s = l->length - 1;
	ft_bzerof(&buff, BUFF_SIZE);
	while (nb)
	{
		buff[s] = ft_llabs(nb % 10) + '0';
		s--;
		nb = nb / 10;
	}
	if (n && l->sfm != 1)
		print_char(l, 3, "-");
	print_char(l, 3, buff);
}

void				ft_print_long(int64_t i, t_args *l, int key)
{
	if (key == 0)
	{
		l->length = get_nblen(i);
		set_pre_lar(l, i);
		if (i == 0 && l->presci == 1)
		{
			zero_except(l);
			return ;
		}
	}
	if (l->plus == 1)
	{
		i >= 0 ? print_char(l, 3, "+") : (void)key;
		l->plus = 0;
	}
	if (i < 0)
	{
		force_print_long(i, l);
		return ;
	}
	if (i >= 10)
		ft_print_long((i / 10), l, 1);
	ft_putchar_fdf(((i % 10) + '0'), l->fd);
	l->len = l->len + 1;
}
