/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sputwchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 18:46:34 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/08 15:35:30 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wchar.h"

static size_t	ft_putwchar_sub(wchar_t *c, char *str, size_t k)
{
	int	i;

	i = k;
	while (i > 0)
	{
		str[i] = 0x80 | ((*c) % 64);
		*c >>= 6;
		i--;
	}
	return (k + 1);
}

size_t			ft_sputwchar(char *str, wchar_t c)
{
	unsigned int	bits;
	size_t			size;

	size = 1;
	bits = ft_wchar_bits(c);
	if (bits <= 7)
		str[0] = c;
	else if (bits <= 11)
	{
		size = ft_putwchar_sub(&c, str, 1);
		str[0] = 0xc0 | c;
	}
	else if (bits <= 16)
	{
		size = ft_putwchar_sub(&c, str, 2);
		str[0] = 0xe0 | c;
	}
	else
	{
		size = ft_putwchar_sub(&c, str, 3);
		str[0] = 0xf0 | c;
	}
	return (size);
}
