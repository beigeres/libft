/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld_digits_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:05:13 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/23 16:37:01 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lld_digits_base(long long int n, unsigned int b)
{
	unsigned long long int	un;
	int						d;

	if (n < 0)
	{
		un = (unsigned long long int)-n;
		d = 2;
	}
	else
	{
		un = (unsigned long long int)n;
		d = 1;
	}
	while (un >= b)
	{
		un /= b;
		d++;
	}
	return (d);
}
