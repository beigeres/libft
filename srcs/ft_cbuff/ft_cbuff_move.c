/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cbuff_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 20:49:00 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/18 20:50:15 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cbuff.h"

void				ft_cbuff_move(t_cbuff *buff, size_t pos_src,
		size_t pos_dest, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)(buff->buff))[(pos_dest + i) % buff->size] =
			((unsigned char *)(buff->buff))[(pos_src + i) % buff->size];
		++i;
	}
}
