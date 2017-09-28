/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:40:38 by kbensado          #+#    #+#             */
/*   Updated: 2017/09/28 17:30:05 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

void	*ft_malloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
	{
		ft_dprintf(2, "MALLOC ERROR RETURN NULL");
		return (NULL);
	}
	ft_bzero(ret, size);
	return (ret);
}

void	*malloc(size_t size)
{
	t_header	*block;

	if (size <= 0)
		return (NULL);
	if (pthread_mutex_lock(&g_malloc_lock[0]) == 22)
	{
		pthread_mutex_init(&g_malloc_lock[0], NULL);
		pthread_mutex_lock(&g_malloc_lock[0]);
	}
	block = handle_sizes(size);
	pthread_mutex_unlock(&g_malloc_lock[0]);
	pthread_mutex_destroy(&g_malloc_lock[0]);
	return (block->mem);
}
