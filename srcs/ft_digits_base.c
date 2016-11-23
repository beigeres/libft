/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:31:11 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/23 15:58:37 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digits_base_f(int n, int b)
{
	int	d;

	d = 1;
	while (n >= b)
	{
		n /= b;
		d++;
	}
	return (d);
}

static int	ft_digits_base_f_neg(int n, int b)
{
	int	d;

	d = 2;
	while (n <= -b)
	{
		n /= b;
		d++;
	}
	return (d);
}

int			ft_digits_base(int n, int b)
{
	return ((n < 0) ? ft_digits_base_f_neg(n, b) : ft_digits_base_f(n, b));
}
