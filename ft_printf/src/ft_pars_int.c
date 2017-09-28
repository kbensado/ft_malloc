/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyrigu <apeyrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 02:19:39 by apeyrigu          #+#    #+#             */
/*   Updated: 2017/02/23 06:52:58 by apeyrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void			ft_convert_wild(t_args *l, va_list ap)
{
	int			tmp;

	tmp = (int)va_arg(ap, int);
	if (tmp < 0)
	{
		if (!l->presci)
			l->less = 1;
		else
			tmp = 0;
		tmp *= -1;
	}
	if (l->presci)
		l->width = tmp;
	else
		l->size = tmp;
	l->flag++;
}

void			ft_pars_int(t_args *l, unsigned char c, va_list ap)
{
	while (ft_strchrf("- +0123456789hljz*.", l->flags[l->flag]) != NULL)
	{
		if (FLAGS_F != c && ft_strchrf("+ -0hljz.", l->flags[l->flag]) != NULL)
		{
			g_signed[(unsigned char)l->flags[l->flag]](l);
			l->flag++;
			continue ;
		}
		if (L_FLAG == '*')
			ft_convert_wild(l, ap);
		if (l->flags[l->flag] > '0' && l->flags[l->flag] <= '9')
		{
			if (l->presci == 0)
				l->size = ft_atoif(l->flags + l->flag);
			while (l->flags[l->flag] >= '0' && l->flags[l->flag] <= '9')
				l->flag++;
		}
	}
	if (FLAGS_F != c)
		l->check = 2;
}
