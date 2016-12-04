/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 18:51:43 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/04 18:53:31 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_wchar_bits(wchar_t c)
{
	unsigned int	a;

	a = 1;
	while (c >= 2)
	{
		a++;
		c /= 2;
	}
	return (a);
}
