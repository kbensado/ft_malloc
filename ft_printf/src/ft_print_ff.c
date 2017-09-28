/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 01:24:08 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/23 14:09:39 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		fill_res(t_args *l)
{
	int		i;
	int		j;

	j = l->x.res_len[1];
	i = ft_strlenf(FLOAT.res_f);
	while (j < l->width)
	{
		l->x.res_f[i] = '0';
		i++;
		j++;
	}
}

void			fill_res_e(t_args *l, int tmp, int len, int i)
{
	int		j;

	j = 0;
	FLOAT.i = 0;
	fill_res(l);
	while (FLOAT.res_f[i])
	{
		if (FLOAT.res_f[i] == '.')
			i++;
		FLOAT.res_e[j] = FLOAT.res_f[i];
		j++;
		if (j == 1)
			FLOAT.res_e[j++] = '.';
		i++;
	}
	round_it_e(l);
	FLOAT.i = j;
	FLOAT.res_len[0]--;
	tmp = FLOAT.res_len[0];
	while (tmp)
	{
		len++;
		tmp = tmp / 10;
	}
	FLOAT.res_len[1] = len;
}

void			print_f(t_args *l, int trigger)
{
	if (l->x.res_len[1] < l->width)
		fill_res(l);
	l->presci && !FLOAT.rwidth ? round_point(l, 0) : (void)l;
	if (l->size > (int)ft_strlenf(l->x.res_f))
		l->padding[0] = l->size - (ft_strlenf(l->x.res_f) + l->plus);
	while (l->padding[0] && l->less == 0 && trigger)
	{
		if (l->plus)
		{
			l->plus--;
			l->x.sign == 1 ? print_char(l, 3, "-") : print_char(l, 3, "+");
		}
		l->zero == 0 ? print_char(l, 0, " ") : print_char(l, 0, "0");
	}
	if (l->plus && trigger)
	{
		l->x.sign == 1 ? print_char(l, 0, "-") : print_char(l, 0, "+");
		print_char(l, 3, l->x.res_f);
	}
	else if (!l->plus && trigger)
	{
		l->x.sign == 1 ? print_char(l, 0, "-") : (void)l;
		print_char(l, 3, l->x.res_f);
	}
	FLOAT.res_fe[0] = ft_strlenf(FLOAT.res_f);
}

int				set_i(t_args *l)
{
	int			i;

	if (FLOAT.rwidth > 0)
		i = l->width + 3;
	else
		i = 2;
	if (FLOAT.res_e[2] == 0)
		i = 2;
	return (i);
}

void			print_e(t_args *l, int i, int trigger)
{
	i = set_i(l);
	if (FLOAT.res_e[i - 1] == '.' && FLOAT.rwidth == 1 &&
		(L_FLAG == 'g' || L_FLAG == 'G'))
		i--;
	FLOAT.res_e[i++] = L_FLAG == 'e' ? 'e' : 'E';
	FLOAT.res_e[i++] = '+';
	R_LEN && (L_FLAG == 'e' || L_FLAG == 'E') ? FLOAT.res_len[0]-- : (void)l;
	if (FLOAT.res_len[0] > 10)
	{
		while (FLOAT.res_len[0])
		{
			FLOAT.res_e[i + FLOAT.res_len[1]] = FLOAT.res_len[0] % 10 + '0';
			FLOAT.res_len[0] = FLOAT.res_len[0] / 10;
			FLOAT.res_len[1]--;
		}
	}
	else
	{
		FLOAT.res_e[i++] = '0';
		FLOAT.res_e[i++] = FLOAT.res_len[0] + '0';
	}
	FLOAT.res_e[i] = 0;
	FLOAT.res_fe[1] = ft_strlenf(FLOAT.res_e);
	if (trigger)
		print_ge(l);
}
