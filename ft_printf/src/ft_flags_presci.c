/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_presci.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyrigu <apeyrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 04:56:50 by apeyrigu          #+#    #+#             */
/*   Updated: 2017/02/21 03:47:40 by apeyrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		ft_flags_presci(t_args *l)
{
	l->presci = 1;
	l->width = ft_atoif(l->flags + l->flag + 1);
	while (l->flags[l->flag] >= '0' && l->flags[l->flag] <= '9')
		l->flag++;
}
