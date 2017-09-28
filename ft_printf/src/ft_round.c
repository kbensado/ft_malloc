/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 02:13:23 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/23 14:08:33 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void			ft_strupp(char buff[], int key)
{
	int			i;

	i = 0;
	while (buff[i] && key == 0)
	{
		if (buff[i] >= 'a' && buff[i] <= 'z')
			buff[i] -= 32;
		i++;
	}
	while (buff[i] && key == 1)
	{
		if (buff[i] >= 'A' && buff[i] <= 'Z')
			buff[i] += 32;
		i++;
	}
}

void			padd_zero(t_args *l, char buff[])
{
	char		tmp[BUFF_SIZE];
	int			i;
	int			j;
	int			tmpi;

	i = 0;
	j = 0;
	tmpi = 0;
	ft_bzerof(&tmp, BUFF_SIZE);
	while (buff[i] != 'x')
		i++;
	tmpi = ++i;
	while (buff[i])
		tmp[j++] = buff[i++];
	while (--l->padding[0])
		buff[tmpi++] = '0';
	while (buff[tmpi] > 0)
		buff[tmpi++] = 0;
	ft_strcatf(buff, tmp);
}

void			had_padd(t_args *l, char buff[])
{
	int			len;

	len = ft_strlenf(buff);
	if (l->less || l->plus)
		l->zero = 0;
	if (len < l->size)
	{
		l->padding[0] = (l->size - len) + l->espace - l->plus;
		while (l->padding[0] && l->less == 0 && !l->zero)
			print_char(l, 0, " ");
		if (l->espace && !FLOAT.sign)
		{
			l->espace = 0;
			print_char(l, 0, " ");
		}
		if (l->zero)
			padd_zero(l, buff);
	}
}

static void		add_one(t_args *l, int i)
{
	if (i < 0)
		return ;
	if (l->x.res_f[i] == '.')
		return ;
	if (l->x.res_f[i] == '9')
	{
		l->x.res_f[i] = '0';
		add_one(l, i - 1);
	}
	else
		l->x.res_f[i]++;
}

void			round_it_e(t_args *l)
{
	int			i;

	i = 0;
	while (FLOAT.res_e[i] != '.')
		i++;
	i = i + FLOAT.rwidth + 1;
	if (l->x.res_e[i] >= '5')
	{
		if (l->x.res_e[i - 1] == '9')
		{
			l->x.res_e[i - 1] = '0';
			add_one(l, i - 2);
		}
		else
			l->x.res_e[i - 1]++;
	}
	while (i < BUFF_SIZE)
		FLOAT.res_e[i++] = 0;
}
