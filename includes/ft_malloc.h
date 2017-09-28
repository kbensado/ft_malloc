/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:43:31 by kbensado          #+#    #+#             */
/*   Updated: 2017/09/28 17:29:12 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include "../ft_printf/inc/ft_printf.h"
# include <sys/mman.h>
# include <pthread.h>

# define TINY 1
# define SMALL 2
# define LARGE 3

# define TS g_mems_list.ts
# define SS g_mems_list.ss
# define TINY_SIZE g_mems_list.tiny_size_max
# define SMALL_SIZE g_mems_list.small_size_max

# define TINY_LEN_MAX (SMALL_LEN_MAX / 4)
# define SMALL_LEN_MAX getpagesize() * 50
# define FLAG_PROT PROT_READ | PROT_WRITE
# define FLAG_MAP MAP_ANON | MAP_PRIVATE
# define SIZE_LEFT (long long)(new->size - size - sizeof(t_header))
# define MAP(x) mmap(0, x, FLAG_PROT, FLAG_MAP, -1 ,0)

typedef struct		s_header
{
	void			*mem;
	size_t			size;
	int				is_free;
	struct s_header	*next;
}					t_header;

typedef struct		s_mem_list
{
	t_header		*tiny;
	t_header		*small;
	t_header		*large;

	size_t			ts;
	size_t			ss;
	size_t			tiny_size_max;
	size_t			small_size_max;
}					t_mem_list;

typedef struct		s_block
{
	t_header		*start;
	t_header		*end;
	t_header		*prev;
	t_header		*selected;

	t_header		**page;
}					t_block;

t_mem_list			g_mems_list;
pthread_mutex_t		g_malloc_lock[5];

void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				free(void *ptr);
void				*calloc(size_t num, size_t nsize);
void				show_alloc_mem(void);
void				*ft_malloc(size_t size);
t_header			*handle_sizes(size_t size);
t_block				*find_ptr_in_page(void *ptr, t_block *block);
int					get_page(size_t size);
t_header			**get_memory_list(int page);
int					is_mem_between(void *ptr, void *start, void *end);
t_header			*create_block(size_t size);
t_header			*set_header(t_header *block, size_t size);
void				insert_header(t_header **list, t_header *block);
t_header			*find_free_mem(t_header **l, size_t s, int p);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);

#endif
