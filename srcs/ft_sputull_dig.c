/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sputull_dig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:50:29 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/23 17:56:47 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sputull_dig(unsigned long long int n, unsigned int base,
		char *str, unsigned int digits)
{
	digits--;
	while (n >= base)
	{
		str[digits] = (n % base) + '0';
		digits--;
		n /= base;
	}
	str[digits] = (n % base) + '0';
}
