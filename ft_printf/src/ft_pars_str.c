/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 02:19:39 by apeyrigu          #+#    #+#             */
/*   Updated: 2017/03/23 14:12:49 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void			ft_pars_str(t_args *l, unsigned char c, va_list ap)
{
	while (ft_strchrf("-l1234567890*. #+", l->flags[l->flag]) != NULL)
	{
		if (FLAGS_F >= '1' && FLAGS_F <= '9' && l->presci == 0)
			l->size = ft_atoif(l->flags + l->flag);
		while (l->flags[l->flag] >= '1' && l->flags[l->flag] <= '9')
		{
			l->flag++;
			continue;
		}
		if (L_FLAG == '*')
			ft_convert_wild(l, ap);
		if (c == l->flags[l->flag])
			break ;
		g_signed[(unsigned char)l->flags[l->flag]](l);
		l->flag++;
	}
	if (FLAGS_F != c)
		l->check = 2;
}
