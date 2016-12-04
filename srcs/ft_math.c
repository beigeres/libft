/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:41:18 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/04 13:54:59 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int						ft_min(int a, int b)
{
	return ((a < b) ? a : b);
}

unsigned int			ft_umin(unsigned int a, unsigned int b)
{
	return ((a < b) ? a : b);
}

unsigned long long int	ft_llabs(long long int n)
{
	return ((n < 0) ? -n : n);
}
