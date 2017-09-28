/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 06:01:45 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/23 14:10:20 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static double	true_digit(double nb)
{
	double		i;
	uint64_t	tmp;

	tmp = nb;
	i = tmp;
	return (i);
}

static double	ft_dabs(double j)
{
	return (j < 0 ? -j : j);
}

static void		pre_buff(uint64_t nb, t_args *l)
{
	uint64_t	tmp;
	uint64_t	tmp2;

	tmp = nb;
	tmp2 = 0;
	while (nb)
	{
		nb = nb / 10;
		tmp2++;
	}
	l->x.i = tmp2;
	if (tmp == 0)
		l->x.res_f[0] = '0';
	while (tmp)
	{
		l->x.i--;
		l->x.res_f[l->x.i] = (tmp % 10) + '0';
		tmp = tmp / 10;
	}
	l->x.i = ft_strlenf(l->x.res_f) + 1;
	if (l->presci == 0 || (l->presci == 1 && l->width > 0))
	{
		l->width--;
		l->x.res_f[l->x.i - 1] = '.';
	}
}

int				len_float(double nb)
{
	int			i;

	i = 0;
	while (nb >= 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

void			ft_modfd(double nb, t_args *l)
{
	double		b;
	int			tmp;

	tmp = l->width;
	b = 0;
	if (nb < 0)
		nb = ft_dabs(nb);
	b = true_digit(nb);
	pre_buff((uint64_t)nb, l);
	nb = nb - b;
	if (nb == 0.0)
	{
		l->x.res_f[l->x.i] = '0';
		FLOAT.rzero = 1;
		FLOAT.exp = 0;
		return ;
	}
	while (tmp != -1)
	{
		nb = nb * 10;
		l->x.res_f[ft_strlenf(FLOAT.res_f)] = true_digit(nb) + '0';
		tmp--;
		nb = nb - true_digit(nb);
		l->x.i++;
	}
}
