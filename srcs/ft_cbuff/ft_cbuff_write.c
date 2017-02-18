/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cbuff_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 20:38:09 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/18 20:54:06 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cbuff.h"

void				ft_cbuff_write(t_cbuff *buff, void *src, size_t pos,
		size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)(buff->buff))[(pos + i) % buff->size] =
			((unsigned char *)(src))[i];
	}
}
