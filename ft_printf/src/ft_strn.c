/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 07:54:04 by apeyrigu          #+#    #+#             */
/*   Updated: 2017/02/26 21:11:46 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int			ft_is_print(int c)
{
	if (c >= 97 && c <= 102)
		return (1);
	if (c >= 48 && c <= 57)
		return (1);
	if (c >= 65 && c <= 70)
		return (1);
	return (0);
}

int					ft_putstr_n(char buff[1024], int size, int key, t_args *l)
{
	int				i;
	int				len;

	len = ft_strlenf(buff);
	i = len;
	if (key == 1 && len == 0)
		l->presci == 1 ? print_char(l, 4, "") : print_char(l, 4, "0");
	while (size)
	{
		if (key == 1)
		{
			if (ft_is_print(buff[len - 1]) == 1 && len > 0)
			{
				write(1, &buff[len - 1], 1);
				l->len++;
			}
		}
		len--;
		size--;
	}
	return (i);
}

void				print_char(t_args *l, int key, char *str)
{
	int				i;
	int				tmp;

	i = 0;
	tmp = 0;
	while (str[i])
	{
		write(l->fd, &str[i], 1);
		i++;
		tmp++;
		l->len = l->len + 1;
	}
	if (key == 0)
		l->padding[0] = l->padding[0] - tmp;
	if (key == 1)
		l->padding[1] = l->padding[1] - tmp;
}
