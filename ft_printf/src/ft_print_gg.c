/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_gg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 01:20:47 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/23 14:09:25 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void				print_ge(t_args *l)
{
	if (l->size > (int)ft_strlenf(l->x.res_e))
		l->padding[0] = l->size - (ft_strlenf(l->x.res_e) + l->plus);
	L_FLAG == 'g' ? ft_strupp(FLOAT.res_e, 1) : (void)l;
	while (l->padding[0] && l->less == 0)
	{
		if (l->plus)
		{
			l->plus--;
			l->x.sign == 1 ? print_char(l, 3, "-") : print_char(l, 3, "+");
		}
		l->zero == 0 ? print_char(l, 0, " ") : print_char(l, 0, "0");
	}
	if (l->plus)
	{
		l->x.sign == 1 ? print_char(l, 0, "-") : print_char(l, 0, "+");
		print_char(l, 3, l->x.res_e);
	}
	else if (!l->plus)
	{
		l->x.sign == 1 ? print_char(l, 0, "-") : (void)l;
		print_char(l, 3, l->x.res_e);
	}
	FLOAT.res_fe[1] = ft_strlenf(FLOAT.res_e);
}

void				print_gf(t_args *l)
{
	if (l->size > (int)ft_strlenf(l->x.res_f))
		l->padding[0] = l->size - (ft_strlenf(l->x.res_f) + l->plus);
	while (l->padding[0] && l->less == 0)
	{
		if (l->plus)
		{
			l->plus--;
			l->x.sign == 1 ? print_char(l, 3, "-") : print_char(l, 3, "+");
		}
		l->zero == 0 ? print_char(l, 0, " ") : print_char(l, 0, "0");
	}
	if (l->plus)
	{
		l->x.sign == 1 ? print_char(l, 0, "-") : print_char(l, 0, "+");
		print_char(l, 3, l->x.res_f);
	}
	else if (!l->plus)
	{
		l->x.sign == 1 ? print_char(l, 0, "-") : (void)l;
		print_char(l, 3, l->x.res_f);
	}
	FLOAT.res_fe[0] = ft_strlenf(FLOAT.res_f);
}

int					true_len_f(t_args *l)
{
	int				i;
	int				res;
	int				tmp;

	i = 0;
	res = 0;
	tmp = FLOAT.rwidth + 1;
	while (FLOAT.res_f[i] && tmp)
	{
		if (FLOAT.res_f[i] >= '0' && FLOAT.res_f[i] <= '9')
		{
			res++;
			tmp--;
			i++;
		}
		else if (FLOAT.res_f[i] == '.')
			i++;
	}
	tmp = ++i;
	while (i < BUFF_SIZE)
	{
		FLOAT.res_f[i++] = 0;
	}
	round_it(l);
	return (tmp);
}

void				r_f_len(t_args *l)
{
	int				i;

	i = 0;
	while (FLOAT.res_f[i])
	{
		if (FLOAT.res_f[i] == '.')
			break ;
		i++;
	}
	FLOAT.rlen_f = i;
}

void				print_g(t_args *l, int tmp)
{
	if ((l->ll && FLOAT.ldnb == 0.0) || (!l->ll && FLOAT.dnb == 0.0))
	{
		print_char(l, 3, "0");
		return ;
	}
	print_e(l, 0, 0);
	print_f(l, 0);
	r_f_len(l);
	FLOAT.res_fe[0] = true_len_f(l);
	if (!had_dec(l))
		round_it(l);
	ft_epure(l);
	(void)tmp;
	FLOAT.res_fe[0] = ft_strlenf(FLOAT.res_f);
	FLOAT.res_fe[1] = ft_strlenf(FLOAT.res_e);
	if (FLOAT.res_fe[0] < FLOAT.res_fe[1] && FLOAT.rwidth >= FLOAT.len_f)
		print_gf(l);
	else
		print_ge(l);
}
