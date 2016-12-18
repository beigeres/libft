/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:31:11 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/18 14:45:02 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base.h"

unsigned int	ft_digits_base(int n, unsigned int b)
{
	return (ft_ll_digits_base((long long int)n, b));
}
