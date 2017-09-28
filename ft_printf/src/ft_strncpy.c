/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 02:50:14 by apeyrigu          #+#    #+#             */
/*   Updated: 2016/12/11 14:03:52 by apeyrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_strncpyf(char *dest, const char *str, size_t len)
{
	size_t i;

	i = 0;
	while (str[i] != '\0' && i < len)
	{
		dest[i] = str[i];
		i++;
	}
	while (i != len)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
