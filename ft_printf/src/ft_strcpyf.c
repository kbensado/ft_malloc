/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpyf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 18:48:46 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/14 03:52:17 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char		*ft_strcatf(char *s1, const char *s2)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (s1[i])
		i++;
	while (s2[k])
	{
		s1[i] = s2[k];
		i++;
		k++;
	}
	s1[i] = '\0';
	return (s1);
}

char		*ft_strcpyf(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
