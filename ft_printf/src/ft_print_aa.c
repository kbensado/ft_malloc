/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_aa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 01:39:39 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/23 14:09:11 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		add_one_hexa(t_args *l, char buff[], int i)
{
	if (i < 0)
		return ;
	if (l->x.res_f[i] == 'f')
	{
		l->x.res_f[i] = '0';
		add_one_hexa(l, buff, i - 1);
	}
	else
	{
		buff[i - 1]++;
		if (buff[i - 1] == ':')
			buff[i - 1] = 'a';
	}
}

void			round_it_hexa(t_args *l, char buff[])
{
	int			i;

	i = ft_strlenf(buff) - 1;
	if (buff[i] >= '9')
	{
		if (buff[i - 1] == 'f')
		{
			buff[i - 1] = '0';
			add_one_hexa(l, buff, i - 2);
		}
		else
		{
			buff[i - 1]++;
			if (buff[i - 1] == ':')
				buff[i - 1] = 'a';
		}
	}
	buff[i] = 0;
}

static void		put_exp(t_args *l, char buff[], int i, int len)
{
	int			tmp;

	tmp = FLOAT.exp;
	if (tmp == 0)
	{
		buff[i] = '0';
		return ;
	}
	if (tmp > 10)
	{
		while (tmp)
		{
			len++;
			tmp /= 10;
		}
	}
	tmp = FLOAT.exp;
	--len < 0 ? len++ : (void)i;
	while (tmp)
	{
		buff[i + len] = tmp % 10 + '0';
		len--;
		tmp /= 10;
	}
}

static void		fill_res_a(t_args *l, char buff[], int r, int i)
{
	int			j;

	j = l->presci == 1 ? FLOAT.rwidth : (int)ft_strlenf(FLOAT.res_a[1]);
	r = j > (int)ft_strlenf(FLOAT.res_a[1]) ? 0 : 1;
	if (j || l->presci)
	{
		j++;
		buff[ft_strlenf(buff)] = '.';
	}
	else
	{
		buff[ft_strlenf(buff)] = buff[ft_strlenf(buff)] >= '9' ? '1' : '2';
		r = 0;
	}
	while (j)
	{
		if (FLOAT.res_a[1][i] > 0 && i >= 0)
			buff[ft_strlenf(buff)] = FLOAT.res_a[1][i];
		else
			buff[ft_strlenf(buff)] = '0';
		i--;
		j--;
	}
	FLOAT.res_a[1][i + 1] == 0 ? buff[ft_strlenf(buff) - 1] = 0 : (void)l;
	r == 1 && l->presci ? round_it_hexa(l, buff) : (void)l;
}

void			print_a(t_args *l)
{
	char		res[BUFF_SIZE];

	ft_bzerof(&res, sizeof(res));
	FLOAT.sign == 1 ? ft_strcpyf(res, "-0x") : ft_strcpyf(res, "0x");
	res[ft_strlenf(res)] = !FLOAT.rzero ? '1' : '0';
	fill_res_a(l, res, 1, (int)ft_strlenf(FLOAT.res_a[1]) - 1);
	res[ft_strlenf(res)] = 'p';
	if (FLOAT.exp >= 0)
		res[ft_strlenf(res)] = '+';
	else
		res[ft_strlenf(res)] = '-';
	put_exp(l, res, ft_strlenf(res), 0);
	had_padd(l, res);
	if (l->espace && !FLOAT.sign)
		print_char(l, 0, " ");
	if (l->plus && FLOAT.sign == 0)
		print_char(l, 3, "+");
	L_FLAG == 'A' ? ft_strupp(res, 0) : (void)l;
	print_char(l, 3, res);
	while (l->padding[0] && l->less == 1)
		print_char(l, 0, " ");
}
