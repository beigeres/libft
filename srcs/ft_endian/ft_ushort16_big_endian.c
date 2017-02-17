/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ushort16_big_endian.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 14:32:53 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/17 14:36:24 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_endian.h"

unsigned short	ft_ushort16_big_endian(unsigned short n)
{
	if (ft_is_big_endian())
		return (n);
	return (((n & 255) << 8) +
			((n >> 8) & 255));
}
