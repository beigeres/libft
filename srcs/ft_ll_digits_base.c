/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_digits_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:59:54 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/23 17:59:55 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_ll_digits_base(long long int n, unsigned int b)
{
	return ((n < 0) ? 1 + ft_ull_digits_base((unsigned long long int)-n, b) :
			ft_ull_digits_base((unsigned long long int)n, b));
}
