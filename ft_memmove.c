/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:39:03 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/06 17:19:16 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	int		inc;
	int		max;

	if (dest > src)
	{
		inc = -1;
		max = -1;
		i = (int)n - 1;
	}
	else
	{
		inc = 1;
		max = (int)n;
		i = 0;
	}
	while (i != max)
	{
		((char*)dest)[i] = ((char*)src)[i];
		i += inc;
	}
	return (dest);
}
