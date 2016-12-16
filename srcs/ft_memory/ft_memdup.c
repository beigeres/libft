/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:35:56 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/16 19:27:06 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memdup(const void *ptr, size_t size)
{
	void	*ret;

	if ((ret = malloc(size)) == NULL)
		return (NULL);
	return (ft_memcpy(ret, ptr, size));
}
