/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 01:12:54 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/14 04:06:15 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void			ft_pars_hexa(t_args *l, unsigned char c, va_list ap)
{
	while (ft_strchrf("#-0123456789hljz*.!+ ", l->flags[l->flag]) != NULL)
	{
		if (FLAGS_F != c && ft_strchrf("#-0hljz.+ ", FLAGS_F) != NULL)
		{
			g_signed[(unsigned char)FLAGS_F](l);
			l->flag++;
			if (FLAGS_F == c)
				return ;
			continue ;
		}
		if (L_FLAG == '*')
			ft_convert_wild(l, ap);
		if (l->presci == 0 && FLAGS_F > '0' && FLAGS_F <= '9' && l->size == 0)
			l->size = ft_atoif(l->flags + l->flag);
		while (FLAGS_F >= '0' && FLAGS_F <= '9')
			l->flag++;
	}
	if (FLAGS_F != c)
		l->check = 2;
}
