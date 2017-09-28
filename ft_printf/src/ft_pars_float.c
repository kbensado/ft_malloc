/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 05:01:33 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/23 14:11:12 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

double				ft_iterative_power(double nb, double power)
{
	double			i;
	double			result;

	i = 1;
	result = nb;
	if (power < 1)
		return (0);
	if (power == 0.0)
		return (1);
	while (i < power)
	{
		result *= nb;
		i++;
	}
	return (result);
}

double				ft_pow10(double value)
{
	double			res;

	res = 0;
	while (value > 1)
	{
		value = value / 10;
		res++;
	}
	return (res);
}

void				set_fstruct(int size, t_args *l, char buff[1024])
{
	if (size == 32)
	{
		l->x.exp_len = 8;
		l->x.exp = 127;
	}
	if (size == 64)
	{
		l->x.exp_len = 11;
		l->x.exp = 1023;
	}
	if (size == 128)
	{
		l->x.exp_len = 15;
		l->x.exp = 16383;
	}
	l->x.sign = (buff[0] == '1');
}

int					ft_exp(char buff[50])
{
	static int		pow[16] = POW15;
	int				res;
	int				i;

	res = 0;
	i = 0;
	while (buff[i])
	{
		if (buff[i] == '1')
		{
			res = res + pow[i];
		}
		i++;
	}
	return (res);
}

void				ft_pars_float(t_args *l, unsigned char c, va_list ap)
{
	while (ft_strchrf("# -+0123456789hlLjz*.", L_FLAG) != NULL)
	{
		if (FLAGS_F != c && ft_strchrf("#+ -0hlLjz.", L_FLAG) != NULL)
		{
			g_signed[(unsigned char)l->flags[l->flag]](l);
			l->flag++;
			continue ;
		}
		if (L_FLAG == '*')
			ft_convert_wild(l, ap);
		if (l->flags[l->flag] > '0' && l->flags[l->flag] <= '9')
		{
			if (l->presci == 0 && l->size == 0)
				l->size = ft_atoif(l->flags + l->flag);
			while (l->flags[l->flag] >= '0' && l->flags[l->flag] <= '9')
				l->flag++;
		}
	}
	if (FLAGS_F != c)
		l->check = 2;
}
