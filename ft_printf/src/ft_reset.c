/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 06:15:27 by apeyrigu          #+#    #+#             */
/*   Updated: 2017/03/14 03:53:00 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		ft_reset(t_args *l)
{
	l->width = 0;
	l->size = 0;
	l->length = 0;
	l->padding[0] = 0;
	l->padding[1] = 0;
	l->padding[2] = 0;
	l->less = 0;
	l->zero = 0;
	l->plus = 0;
	l->star = 0;
	l->espace = 0;
	l->hastag = 0;
	l->presci = 0;
	l->h = 0;
	l->l = 0;
	l->ll = 0;
	l->m = 0;
	l->j = 0;
	l->z = 0;
	l->base[0] = 0;
	l->base[1] = 0;
	l->flag = 0;
	ft_bzerof(l->flags, sizeof(l->flags));
	ft_bzerof(&l->x, sizeof(l->x));
	l->check = (l->check == 1 ? 1 : 0);
}

void		ft_epure(t_args *l)
{
	int		i;

	i = ft_strlenf(FLOAT.res_f) - 1;
	while (FLOAT.res_f[i] == '0')
	{
		FLOAT.res_f[i] = 0;
		i--;
	}
	if (FLOAT.res_f[i] == '.')
		FLOAT.res_f[i] = 0;
	FLOAT.res_fe[0] = ft_strlenf(FLOAT.res_f);
	i = -1;
	while (FLOAT.res_f[++i])
		if (FLOAT.res_f[i] >= '0' && FLOAT.res_f[i] <= '9')
			FLOAT.len_f++;
}
