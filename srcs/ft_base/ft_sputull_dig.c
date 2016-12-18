/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sputull_dig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:50:29 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/18 14:46:48 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base.h"

void	ft_sputull_dig(unsigned long long int n, t_base *base,
		char *str, unsigned int digits)
{
	return (ft_sputuintmax_dig((uintmax_t)n, base, str, digits));
}
