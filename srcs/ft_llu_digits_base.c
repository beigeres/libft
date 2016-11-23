/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llu_digits_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:12:18 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/23 16:50:30 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_llu_digits_base(unsigned long long int n, unsigned int base)
{
	int	a;

	a = 1;
	while (n >= (unsigned long long int)base)
	{
		a++;
		n /= base;
	}
	return (a);
}
