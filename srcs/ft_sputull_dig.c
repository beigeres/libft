/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sputull_dig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:50:29 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/24 12:00:05 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sputull_dig(unsigned long long int n, t_base *base,
		char *str, unsigned int digits)
{
	digits--;
	while (n >= base->size)
	{
		str[digits] = base->str[n % base->size];
		digits--;
		n /= base->size;
	}
	str[digits] = base->str[n % base->size];
}
