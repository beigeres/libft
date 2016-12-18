/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_dig.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 18:57:11 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/05 17:10:26 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wchar.h"

unsigned int	ft_wchar_dig(wchar_t c)
{
	unsigned int	bits;

	bits = ft_wchar_bits(c);
	if (bits <= 7)
		return (1);
	else if (bits <= 11)
		return (2);
	else if (bits <= 16)
		return (3);
	else
		return (4);
}
