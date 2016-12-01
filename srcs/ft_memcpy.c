/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:38:55 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/01 18:04:52 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_t;
	char	*src_t;

	dest_t = (char*)dest;
	src_t = (char*)src;
	while (n > 0)
	{
		*dest_t = *src_t;
		dest_t++;
		src_t++;
		n--;
	}
	return (dest);
}
