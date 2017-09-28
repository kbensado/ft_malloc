/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 03:34:30 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/23 14:10:10 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int				stranger_digit(double nb, t_args *l)
{
	if (nb == 0x7fffffffffffffff)
	{
		if (L_FLAG == 'f')
			print_char(l, 3, "nan");
		else if (L_FLAG == 'F')
			print_char(l, 3, "NAN");
		return (1);
	}
	else if (nb == 0xfff0000000000000)
	{
		if (L_FLAG == 'f')
			print_char(l, 3, "-infinity");
		if (L_FLAG == 'F')
			print_char(l, 3, "-INFINITY");
		return (1);
	}
	else if (nb == 0x7ff0000000000000)
	{
		if (L_FLAG == 'f')
			print_char(l, 3, "infinity");
		if (L_FLAG == 'F')
			print_char(l, 3, "INFINITY");
		return (1);
	}
	return (0);
}

int				had_dec(t_args *l)
{
	int			i;
	int			key;
	int			ret;

	i = 0;
	key = 0;
	ret = 1;
	while (FLOAT.res_f[i])
	{
		key == 0 ? FLOAT.res_len[0]++ : FLOAT.res_len[1]++;
		if (FLOAT.res_f[i] == '.')
		{
			FLOAT.res_len[0]--;
			key++;
		}
		if (FLOAT.res_f[i] > '0' && key == 1)
		{
			FLOAT.dec = 1;
			ret = 0;
		}
		i++;
	}
	return (ret);
}

static void		add_one(t_args *l, int i)
{
	if (i < 0)
		return ;
	if (FLOAT.res_f[i] == '9')
	{
		FLOAT.res_f[i] = '0';
		add_one(l, i - 1);
	}
	else if (FLOAT.res_f[i] == '.')
	{
		if (FLOAT.res_f[i - 1] == '9')
		{
			FLOAT.res_f[i - 1] = '0';
			add_one(l, i - 2);
		}
		else
			FLOAT.res_f[i - 1]++;
	}
	else
		FLOAT.res_f[i]++;
}

void			round_it(t_args *l)
{
	int			i;

	i = ft_strlenf(FLOAT.res_f) - 1;
	if (FLOAT.res_f[i] >= '5')
	{
		if (FLOAT.res_f[i - 1] == '9')
		{
			FLOAT.res_f[i - 1] = '0';
			add_one(l, i - 2);
		}
		else if (FLOAT.res_f[i - 1] == '.')
		{
			if (FLOAT.res_f[i - 2] == '9')
			{
				FLOAT.res_f[i - 2] = '0';
				add_one(l, i - 3);
			}
			else
				FLOAT.res_f[i - 2]++;
		}
		else
			FLOAT.res_f[i - 1]++;
	}
	FLOAT.res_f[i] = 0;
}

void			ft_print_float(t_args *l)
{
	if (!had_dec(l))
		round_it(l);
	if (L_FLAG == 'F' || L_FLAG == 'f')
		print_f(l, 1);
	else if (L_FLAG == 'e' || L_FLAG == 'E')
	{
		fill_res_e(l, 0, 0, 0);
		print_e(l, 0, 1);
	}
	else if (L_FLAG == 'a' || L_FLAG == 'A')
		print_a(l);
	else if (L_FLAG == 'g' || L_FLAG == 'G')
		print_g(l, FLOAT.rwidth);
	ft_bzerof(&FLOAT, sizeof(FLOAT));
}
