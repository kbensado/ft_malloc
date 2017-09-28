/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 04:39:29 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/23 14:10:33 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void			print_res_float(t_args *l, int i)
{
	while (i)
		i--;
	(void)l;
}

static void			convert_aa(int size, char *base_ref, t_args *l, int tmp)
{
	static int		pow[4] = {1, 2, 4, 8};
	int				res;

	res = 0;
	if (size == 31)
	{
		size++;
		l->x.res_a[0][size] = '0';
	}
	while (size != l->x.exp_len)
	{
		if (l->x.res_a[0][size] == '1')
			res = res + pow[tmp];
		tmp++;
		if (tmp == 4)
		{
			l->x.res_a[1][FLOAT.i++] = base_ref[res];
			res = 0;
			tmp = 0;
		}
		size--;
	}
	if (0 != res)
		l->x.res_a[1][FLOAT.i] = base_ref[res];
	print_res_float(l, FLOAT.i);
}

static void			convert_float(int size, t_args *l, int tmp)
{
	int				i;
	char			buff2[50];

	ft_bzerof(&buff2, 50);
	set_fstruct(size + 1, l, l->x.res_a[0]);
	i = l->x.exp_len;
	while (i >= 1 && i <= l->x.exp_len)
	{
		if (l->x.res_a[0][i] == '1')
			buff2[tmp++] = '1';
		else
			buff2[tmp++] = '0';
		i--;
	}
	l->x.exp = ft_exp(buff2) - l->x.exp;
	if (size == 31)
	{
		size++;
		l->x.res_a[0][size] = '0';
	}
	if (L_FLAG == 'a' || L_FLAG == 'A')
	{
		FLOAT.i = 0;
		convert_aa(size, L_FLAG == 'a' ? LOWER_BASE : UPPER_BASE, l, 0);
	}
}

int					check_float(size_t size, void *ptr, t_args *l)
{
	unsigned char	*b;
	unsigned char	byte;
	int				i;
	size_t			k;
	int				j;

	b = (unsigned char *)ptr;
	byte = 0;
	k = 0;
	i = size - 1;
	j = 7;
	while (i != -1)
	{
		while (j != -1)
		{
			byte = (b[i] >> j) & 1;
			l->x.res_a[0][k] = byte == 1 ? '1' : '0';
			k++;
			j--;
		}
		j = 7;
		i--;
	}
	convert_float(k - 1, l, 0);
	return (k);
}

void				ft_float(va_list ap, t_args *l)
{
	FLOAT.rwidth = l->width;
	l->width < 6 && l->presci == 0 ? l->width = 6 : (void)l;
	L_FLAG == 'g' || L_FLAG == 'G' ? l->width-- : (void)l;
	if (l->ll == 1)
	{
		FLOAT.ldnb = (long double)va_arg(ap, long double);
		check_float(sizeof(FLOAT.ldnb), &FLOAT.ldnb, l);
		ft_modfd(FLOAT.ldnb, l);
	}
	else
	{
		FLOAT.dnb = (double)va_arg(ap, double);
		if (stranger_digit(FLOAT.dnb, l))
			return ;
		check_float(sizeof(FLOAT.dnb), &FLOAT.dnb, l);
		ft_modfd(FLOAT.dnb, l);
	}
	ft_print_float(l);
	if (l->less == 1)
		while (l->padding[0] > 0)
			print_char(l, 0, " ");
}
