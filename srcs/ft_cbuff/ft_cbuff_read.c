/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cbuff_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 20:50:42 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/03 22:52:52 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cbuff.h"

void				ft_cbuff_read(t_cbuff *buff, void *dest, size_t pos,
		size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)(dest))[i] =
			((unsigned char *)(buff->buff))[(pos + i) % buff->size];
		++i;
	}
}
