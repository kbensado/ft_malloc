/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xoxo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 00:45:43 by apeyrigu          #+#    #+#             */
/*   Updated: 2017/02/26 21:01:13 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int					the_stronger_hexa(t_args *l)
{
	int		tmp;

	tmp = 0;
	if (l->width >= l->length)
		tmp = l->width;
	else
		tmp = l->length;
	l->padding[0] = l->size - tmp;
	l->padding[1] = l->width - l->length;
	if (l->length >= l->size && l->length >= l->width)
		return (0);
	if (l->width >= l->size && l->width >= l->length)
		return (1);
	return (2);
}

void				convert(char buff[2][1024], int size,
					char *base_ref, t_args *l)
{
	static int		pow[4] = {1, 2, 4, 8};
	int				i;
	int				tmp;
	int				res;

	i = 0;
	tmp = 0;
	res = 0;
	while (size != -1)
	{
		if (buff[0][size] == '1')
			res = res + pow[tmp];
		tmp++;
		if (tmp == l->base[0])
		{
			buff[1][i] = base_ref[res];
			res = 0;
			tmp = 0;
			i++;
		}
		size--;
	}
	if (0 != res)
		buff[1][i] = base_ref[res];
	print_res(buff[1], l, ft_strlenf(buff[1]));
}

int					check_bits(size_t size, void *ptr,
					char buff[2][1024], t_args *l)
{
	unsigned char	*b;
	unsigned char	byte;
	int				i;
	size_t			k;
	int				j;

	b = (unsigned char *)ptr;
	byte = 0;
	k = 0;
	i = size - 1;
	j = 7;
	while (i != -1)
	{
		while (j != -1)
		{
			byte = (b[i] >> j) & 1;
			buff[0][k] = byte == 1 ? '1' : '0';
			k++;
			j--;
		}
		j = 7;
		i--;
	}
	convert(buff, k - 1, l->base[1] == 0 ? UPPER_BASE : LOWER_BASE, l);
	return (k);
}

void				convert_base(t_args *l, char buff[2][1024])
{
	if (l->h == 1 && 0 == l->l)
		check_bits(sizeof(short), (short *)&l->unb, buff, l);
	else if (l->h == 2 && 0 == l->l)
		check_bits(sizeof(uint8_t), (uint8_t *)&l->unb, buff, l);
	else if (l->l == 1)
		check_bits(sizeof(long), (long *)&l->unb, buff, l);
	else if (l->l == 2)
		check_bits(sizeof(long long), (long long *)&l->unb, buff, l);
	else if (l->j == 1)
		check_bits(sizeof(intmax_t), (intmax_t *)&l->unb, buff, l);
	else if (l->z == 1)
		check_bits(sizeof(size_t), (size_t *)&l->unb, buff, l);
	else if (l->z == 2)
		check_bits(sizeof(void *), (void *)&l->unb, buff, l);
	else
		check_bits(sizeof(int), (int *)&l->unb, buff, l);
}

void				ft_base(va_list ap, t_args *l)
{
	char			buff[2][1024];

	ft_bzerof(&buff, 2048);
	convert_option(l);
	if (l->flags[l->flag] == 'O' && 0 == l->l)
		l->l = 1;
	if (1 == l->h && 0 == l->l)
		l->unb = (short)va_arg(ap, int);
	else if (l->h == 2 && 0 == l->l)
		l->unb = (char)va_arg(ap, int);
	else if (l->l == 1)
		l->unb = (long)va_arg(ap, long);
	else if (l->l == 2)
		l->unb = (long long)va_arg(ap, long long);
	else if (l->j == 1)
		l->unb = (intmax_t)va_arg(ap, intmax_t);
	else if (l->z == 1)
		l->unb = (size_t)va_arg(ap, size_t);
	else
		l->unb = (int)va_arg(ap, int);
	convert_base(l, buff);
	if (l->less == 1)
		while (l->padding[0] > 0)
			l->zero == 1 ? print_char(l, 0, "0") : print_char(l, 0, " ");
}
