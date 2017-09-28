/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyrigu <apeyrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 00:06:31 by apeyrigu          #+#    #+#             */
/*   Updated: 2017/02/23 07:09:05 by apeyrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_putnstr(char *s, int size, int key)
{
	if (key == 1)
		while (key != size--)
			write(1, " ", 1);
	else
		while (key != size)
			write(1, &s[key++], 1);
}

void	ft_print_str(char *s, t_args *l, int key)
{
	if (key == 1)
	{
		if (l->less == 1)
			ft_putnstr(s, l->padding[1], 0);
		ft_putnstr(s, l->padding[2] + 1, 1);
		if (l->less == 0)
			ft_putnstr(s, l->padding[1], 0);
	}
	if (key == 2)
		ft_putnstr(s, l->padding[2], 0);
}

void	ft_size_max(char *s, t_args *l)
{
	if (s == NULL)
		s = ALED;
	l->length = ft_strlenf(s);
	if (l->size > l->length)
	{
		l->padding[0] = l->size;
		if (l->presci == 1)
			l->padding[1] = l->length >= l->width ? l->width : l->length;
		else
			l->padding[1] = l->length;
		l->padding[2] = l->padding[0] - l->padding[1];
		l->len = l->len + l->size;
		ft_print_str(s, l, 1);
	}
	else
	{
		if (l->width != 0)
			l->padding[2] = l->length > l->width ? l->width : l->length;
		else
			l->padding[2] = l->length;
		l->len += l->padding[2];
		ft_print_str(s, l, 2);
	}
}

void	ft_str(va_list ap, t_args *l)
{
	if (l->l == 1)
		l->l = 0;
	else
		ft_size_max((char *)va_arg(ap, char *), l);
}
