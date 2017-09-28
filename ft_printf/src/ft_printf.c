/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 09:16:24 by apeyrigu          #+#    #+#             */
/*   Updated: 2017/09/28 16:53:11 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static const	t_func	g_omer[] =
{
	['d'] = ft_int,
	['f'] = ft_float,
	['F'] = ft_float,
	['a'] = ft_float,
	['A'] = ft_float,
	['g'] = ft_float,
	['G'] = ft_float,
	['e'] = ft_float,
	['E'] = ft_float,
	['i'] = ft_int,
	['b'] = ft_base,
	['o'] = ft_base,
	['x'] = ft_base,
	['D'] = ft_int,
	['u'] = ft_unsigned,
	['U'] = ft_unsigned,
	['O'] = ft_base,
	['X'] = ft_base,
	['s'] = ft_str,
	['c'] = ft_char,
	['%'] = ft_prcent,
	['p'] = ft_pointer,
};

static const	t_pars	g_parseur[] =
{
	['s'] = ft_pars_str,
	['d'] = ft_pars_int,
	['D'] = ft_pars_int,
	['i'] = ft_pars_int,
	['a'] = ft_pars_float,
	['A'] = ft_pars_float,
	['e'] = ft_pars_float,
	['E'] = ft_pars_float,
	['f'] = ft_pars_float,
	['F'] = ft_pars_float,
	['g'] = ft_pars_float,
	['G'] = ft_pars_float,
	['u'] = ft_pars_int,
	['U'] = ft_pars_int,
	['x'] = ft_pars_hexa,
	['X'] = ft_pars_hexa,
	['o'] = ft_pars_hexa,
	['O'] = ft_pars_hexa,
	['b'] = ft_pars_hexa,
	['c'] = ft_pars_str,
	['%'] = ft_pars_str,
	['p'] = ft_pars_hexa,
};

static int		ft_pass_arg(char const *p, t_args *l, int i, va_list ap)
{
	int			j;

	i++;
	j = i;
	while (ft_strchrf("fFaAgGeEsSdDoOuUxXcCbpi%%\0", p[i]) == NULL)
		i++;
	if (p[i] == '\0')
	{
		write(1, p + j, i - j);
		l->len = l->len + i - 2;
		return (-1);
	}
	l->c = p[i];
	ft_strncpyf(l->flags, p + j, i + 1);
	g_parseur[(unsigned char)l->c](l, l->c, ap);
	if (l->check == 2)
	{
		l->c = '%';
		while (p[i] != '%' && p[i])
			i++;
		ft_strncpyf(l->flags, p + j, i + 1);
		return (i);
	}
	return (i + 1);
}

static void		ft_printf_engine(char const *p, va_list ap, t_args *x)
{
	int			i;

	i = 0;
	NM;
	while (*p && (i = 0) == 0 && x->check != 1)
	{
		while (p[i] && p[i] != '%')
			i++;
		i > 0 ? write(1, p, i) : (void)ap;
		x->len = x->len + i;
		if (p[i] == '%')
		{
			if ((i = ft_pass_arg(p, x, i, ap)) != -1)
			{
				p = p + i;
				g_omer[(unsigned char)x->c](ap, x);
				ft_reset(x);
				continue ;
			}
			return ;
		}
		p = p + i;
	}
}

int				ft_printf(char const *format, ...)
{
	va_list		ap;
	t_args		x;

	ft_bzerof((void *)&x, sizeof(t_args));
	x.fd = 1;
	va_start(ap, format);
	ft_reset(&x);
	ft_printf_engine(format, ap, &x);
	va_end(ap);
	return (x.len);
}

int				ft_dprintf(int fd, char const *format, ...)
{
	va_list		ap;
	t_args		x;

	ft_bzerof((void *)&x, sizeof(t_args));
	x.fd = fd;
	va_start(ap, format);
	ft_reset(&x);
	ft_printf_engine(format, ap, &x);
	va_end(ap);
	return (x.len);
}
