/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 00:59:33 by apeyrigu          #+#    #+#             */
/*   Updated: 2017/09/28 16:56:01 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define P printf
# define ALED "(null)"
# define ADRESS ft_putstr_n(buff, size * 1.5, 1, l)
# define FLAGS_F l->flags[l->flag]
# define BUFF_SIZE 4096
# define UPPER_BASE "0123456789ABCDEF"
# define LOWER_BASE "0123456789abcdef"
# define L_FLAG l->flags[l->flag]
# define FLOAT l->x
# define POW15 {1,2,4,8,16,32,64,128,256,514,1024,2048,4096,8192,16384,32768}
# define INFINITE "0000000000000ff7"
# define LEE_INFINITE "0000000000000fff"
# define NAN "fffffffffffffff7"
# define ONE_THREE "5555555555555555df3"
# define R_LEN !FLOAT.rwidth && l->presci && FLOAT.res_len[0] != 0
# define L_OR_LL FLOAT.dnb == 0 ? sizeof(FLOAT.ldnb) : sizeof(FLOAT.dnb)
# define NM ft_strlenf(p)==1?(p[0]=='%' ? x->check = 1 : (void)ap) : (void)ap;
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <wctype.h>
# include <inttypes.h>
# include <stdint.h>
# include <limits.h>
# include <float.h>

/*
**	res_len[0] pour conversion f et 1 pour conversion e
*/

typedef struct			s_float
{
	int					exp;
	char				exp_buff[5];
	long double			mantissa;
	double				nb;
	int					sign;
	int					exp_len;
	int					len_f;
	int					rlen_f;
	char				res_a[2][BUFF_SIZE];
	char				res_f[BUFF_SIZE];
	char				res_e[BUFF_SIZE];
	int					i;
	int					res_len[2];
	int					res_fe[2];
	int					dec;
	int					rzero;
	int					rwidth;
	double				dnb;
	long double			ldnb;

}						t_float;

typedef struct			s_args
{
	char				flags[50];
	char				ch[2];
	int					flag;
	int					fd;
	int					len;
	int					c;
	int					check;
	int					less;
	int					zero;
	int					plus;
	int					star;
	int					espace;
	int					hastag;
	int					presci;
	int					size;
	int					width;
	int					length;
	int					padding[3];
	int					base[2];
	int					sfm;
	int					h;
	int					l;
	int					ll;
	int					m;
	int					j;
	int					z;
	t_float				x;
	uint64_t			unb;
}						t_args;

typedef	void			(*t_flags)(t_args *l);
typedef void			(*t_func)(va_list ap, t_args *l);
typedef	void			(*t_pars)(t_args *l, unsigned char c, va_list ap);
int						ft_printf(char const *format, ...);
int						ft_dprintf(int fd, char const *format, ...);

/*
**Parsseur	 					:: *t_pars
*/

void					ft_pars_int(t_args *l, unsigned char c, va_list ap);
void					ft_pars_float(t_args *l, unsigned char c, va_list ap);
void					ft_pars_hexa(t_args *l, unsigned char c, va_list ap);
void					ft_pars_str(t_args *l, unsigned char c, va_list ap);

/*
**Fonctions qui traite et affiche :: *t_func
*/

void					ft_print_ulong(uint64_t i, t_args *l, int key);
void					ft_print_long(int64_t i, t_args *l, int key);
void					ft_int(va_list ap, t_args *l);
void					ft_float(va_list ap, t_args *l);
void					ft_unsigned(va_list ap, t_args *l);
void					ft_base(va_list ap, t_args *l);
void					ft_str(va_list ap, t_args *l);
void					ft_size_max(char *s, t_args *l);
void					ft_print_str(char *s, t_args *l, int key);
void					ft_prcent(va_list ap, t_args *l);
void					ft_char(va_list ap, t_args *l);
void					ft_pointer(va_list ap, t_args *l);
int						ft_putstr_n(char buff[1024], int size,
						int key, t_args *l);
void					print_char(t_args *l, int key, char *str);
void					convert_option(t_args *l);
void					ft_print_float(t_args *l);
void					fill_res_e(t_args *l, int tmp, int len, int i);
void					print_ge(t_args *l);
void					print_gf(t_args *l);
void					print_g(t_args *l, int tmp);
void					print_e(t_args *l, int i, int trigger);
void					print_f(t_args *l, int trigger);
void					print_a(t_args *l);

/*
**Fonctions flags et convertions :: *t_flags
*/

void					ft_flags_espace(t_args *l);
void					ft_flags_hastag(t_args *l);
void					ft_flags_less(t_args *l);
void					ft_flags_plus(t_args *l);
void					ft_flags_zero(t_args *l);
void					ft_flags_presci(t_args *l);
void					ft_convert_h(t_args *l);
void					ft_convert_l(t_args *l);
void					ft_convert_ll(t_args *l);
void					ft_convert_j(t_args *l);
void					ft_convert_z(t_args *l);
void					ft_convert_wild(t_args *l, va_list ap);

/*
**Fonctions						:: autre
*/

void					ft_epure(t_args *l);
int						the_stronger_hexa(t_args *l);
int						get_nblen(long long nb);
int						the_stronger(t_args *l, int64_t nb);
void					set_pre_lar_hex(t_args *l, int key);
void					convert_base(t_args *l, char buff[2][1024]);
void					ft_reset(t_args *l);
void					convert_option(t_args *l);
void					do_padding_z(t_args *l, int64_t nb);
void					print_res(char buff[1024], t_args *l, int len);
void					convert(char buff[2][1024], int size,
						char *base_ref, t_args *l);
int						check_bits(size_t size, void *ptr,
						char buff[2][1024], t_args *l);
int						ft_exp(char buff[50]);
void					set_fstruct(int size, t_args *l, char buff[1024]);
void					ft_modfd(double nb, t_args *l);
double					db_round(double value);
int						stranger_digit(double nb, t_args *l);
int						had_dec(t_args *l);
void					round_it(t_args *l);
void					round_it_e(t_args *l);
void					padd_zero(t_args *l, char buff[]);
void					had_padd(t_args *l, char buff[]);
void					ft_strupp(char buff[], int key);
void					zero_except(t_args *l);
void					res_except(t_args *l, char buff[], int tmp);
void					round_point(t_args *l, int i);

/*
**Libft
*/

double					ft_iterative_powerf(double nb, double power);
long long				ft_llabsf(long long j);
char					*ft_strcpyf(char *dst, const char *src);
void					print_char(t_args *l, int key, char *str);
int						ft_atoif(const char *str);
void					ft_bzerof(void *s, size_t n);
void					ft_putchar_fdf(char c, int fd);
char					*ft_strchrf(const char *s, int c);
size_t					ft_strlenf(const char *s);
double					ft_pow10(double value);
char					*ft_strcatf(char *s1, const char *s2);
int						ft_is_digitf(int c);
char					*ft_strncpyf(char *dest, const char *str, size_t len);

static const	t_flags g_signed[] =
{
	['#'] = ft_flags_hastag,
	['0'] = ft_flags_zero,
	[' '] = ft_flags_espace,
	['-'] = ft_flags_less,
	['+'] = ft_flags_plus,
	['.'] = ft_flags_presci,
	['h'] = ft_convert_h,
	['l'] = ft_convert_l,
	['L'] = ft_convert_ll,
	['j'] = ft_convert_j,
	['z'] = ft_convert_z,
};

#endif
