/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_prcent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyrigu <apeyrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 00:06:31 by apeyrigu          #+#    #+#             */
/*   Updated: 2017/02/23 07:11:13 by apeyrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_undef(t_args *l)
{
	int	i;

	i = 0;
	if (l->flags[0] == ' ')
		i = 1;
	l->len = l->len + ft_strlenf(l->flags) + -i;
	write(1, l->flags + i, sizeof(l->flags));
	return (0);
}

void	ft_prcent(va_list ap, t_args *l)
{
	int i;

	i = 1;
	if (l->check == 2 && ft_undef(l) == 0)
		return ;
	if (l->size > 0)
	{
		l->len = l->len + l->size - 1;
		if (l->less == 1)
			write(1, "%%", 1);
		while (i != l->size)
		{
			write(1, " ", 1);
			i++;
		}
		if (l->less == 0)
			write(1, "%%", 1);
	}
	else
		write(1, "%%", 1);
	l->len = l->len + 1;
	(void)ap;
}
