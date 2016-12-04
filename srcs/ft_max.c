/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:37:20 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/03 17:37:52 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int						ft_max(int a, int b)
{
	return ((a > b) ? a : b);
}

unsigned int			ft_umax(unsigned int a, unsigned int b)
{
	return ((a > b) ? a : b);
}

uintmax_t				ft_intmaxabs(intmax_t n)
{
	return ((n < 0) ? -n : n);
}

intmax_t				ft_intmaxmax(intmax_t a, intmax_t b)
{
	return ((a > b) ? a : b);
}
