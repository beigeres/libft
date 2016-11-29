/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:41:18 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/25 16:16:24 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int						ft_max(int a, int b)
{
	return ((a > b) ? a : b);
}

int						ft_min(int a, int b)
{
	return ((a < b) ? a : b);
}

unsigned int			ft_umax(unsigned int a, unsigned int b)
{
	return ((a > b) ? a : b);
}

unsigned long long int	ft_llabs(long long int n)
{
	return ((n < 0) ? -n : n);
}

uintmax_t				ft_intmaxabs(intmax_t n)
{
	return ((n < 0) ? -n : n);
}

intmax_t				ft_intmaxmax(intmax_t a, intmax_t b)
{
	return ((a > b) ? a : b);
}
