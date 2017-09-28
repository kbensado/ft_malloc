/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_memory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 18:18:35 by kbensado          #+#    #+#             */
/*   Updated: 2017/08/05 00:30:36 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

static void	print_header(t_header *tmp)
{
	ft_printf("[");
	if (tmp->is_free)
		ft_printf("V]");
	else
		ft_printf("X]");
	ft_printf("%p - %p : %d\
	octets\n", tmp->mem, tmp->size + tmp->mem, tmp->size);
}

static int	print_page_memory(char *page, t_header *list)
{
	t_header	*tmp;
	int			total;

	total = 0;
	tmp = list;
	ft_printf("%s %p\n", page, list);
	while (tmp)
	{
		print_header(tmp);
		total += tmp->size + sizeof(t_header);
		tmp = tmp->next;
	}
	ft_printf("\nTotal: %d\n", total);
	return (total);
}

void		show_alloc_mem(void)
{
	int	total;
	int	mutex;

	total = 0;
	mutex = pthread_mutex_lock(&g_malloc_lock[4]);
	if (mutex == 16 || mutex == 22)
	{
		pthread_mutex_init(&g_malloc_lock[4], NULL);
		pthread_mutex_lock(&g_malloc_lock[4]);
	}
	total = print_page_memory("TINY ", g_mems_list.tiny);
	total += print_page_memory("SMALL ", g_mems_list.small);
	total += print_page_memory("LARGE ", g_mems_list.large);
	ft_printf("-----------------------------------------\n");
	pthread_mutex_unlock(&g_malloc_lock[4]);
	pthread_mutex_destroy(&g_malloc_lock[4]);
}
