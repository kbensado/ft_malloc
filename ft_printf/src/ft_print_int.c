/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 00:16:54 by apeyrigu          #+#    #+#             */
/*   Updated: 2017/03/23 13:49:38 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	check_the_d(t_args *l)
{
	if (l->flags[l->flag] == 'D')
	{
		l->h = 0;
		l->l = 1;
	}
	if (l->flags[l->flag] == 'U')
	{
		l->h = 0;
		l->l = 1;
		l->plus = 0;
	}
	if (l->flags[l->flag] == 'u')
		l->plus = 0;
}

/*
**	return who is the stronger beetween the r_len preci, larg
**	and set the padding for larg prec and shit
**	return the strongest
**	0 r_len
**	1 preci
**	2 larg
*/

int		the_stronger(t_args *l, int64_t nb)
{
	int		tmp;

	tmp = 0;
	if (l->width >= l->length)
		tmp = l->width;
	else
		tmp = l->length;
	l->padding[0] = l->size - tmp;
	l->padding[1] = l->width - l->length;
	(void)nb;
	if (l->plus == 1 && nb > 0 && !l->zero && !l->less)
		l->padding[0]--;
	if (l->length >= l->size && l->length >= l->width)
		return (0);
	if (l->width >= l->size && l->width >= l->length)
		return (1);
	return (2);
}

/*
** get the real len of nb
*/

int		get_nblen(long long nb)
{
	int		res;

	res = 0;
	if (nb < 0)
		nb = nb * -1;
	while (nb)
	{
		res++;
		nb = nb / 10;
	}
	if (res == 0)
		res++;
	return (res);
}

void	ft_unsigned(va_list ap, t_args *l)
{
	check_the_d(l);
	if (l->h == 1)
		ft_print_ulong((unsigned short)va_arg(ap, size_t), l, 0);
	else if (l->h == 2)
		ft_print_ulong((unsigned char)va_arg(ap, size_t), l, 0);
	else if (l->l == 1)
		ft_print_ulong((unsigned long)va_arg(ap, unsigned long), l, 0);
	else if (l->l == 2)
		ft_print_ulong(
		(unsigned long long)va_arg(ap, unsigned long long), l, 0);
	else if (l->j == 1)
		ft_print_ulong((intmax_t)va_arg(ap, intmax_t), l, 0);
	else if (l->z == 1)
		ft_print_ulong((size_t)va_arg(ap, size_t), l, 0);
	else
		ft_print_ulong((size_t)va_arg(ap, size_t), l, 0);
	if (l->less == 1)
		while (l->padding[0] > 0)
			print_char(l, 0, " ");
}

void	ft_int(va_list ap, t_args *l)
{
	check_the_d(l);
	if (l->h == 1)
		ft_print_long((short)va_arg(ap, int), l, 0);
	else if (l->h == 2)
		ft_print_long((char)va_arg(ap, int), l, 0);
	else if (l->l == 1)
		ft_print_long((long)va_arg(ap, long), l, 0);
	else if (l->l == 2)
		ft_print_long((long long)va_arg(ap, long long), l, 0);
	else if (l->j == 1)
		ft_print_long((intmax_t)va_arg(ap, intmax_t), l, 0);
	else if (l->z == 1)
		ft_print_long((size_t)va_arg(ap, size_t), l, 0);
	else
		ft_print_long((int)va_arg(ap, int), l, 0);
	if (l->less == 1)
		while (l->padding[0] > 0)
			print_char(l, 0, " ");
}
