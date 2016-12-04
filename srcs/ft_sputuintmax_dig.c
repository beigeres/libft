/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sputuintmax_dig.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 20:24:51 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/04 20:26:55 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base.h"

void	ft_sputuintmax_dig(uintmax_t n, t_base *base,
		char *str, unsigned int digits)
{
	if (digits == 0)
		return ;
	digits--;
	while (digits > 0)
	{
		str[digits] = base->str[n % base->size];
		digits--;
		n /= base->size;
	}
	str[digits] = base->str[n % base->size];
}
