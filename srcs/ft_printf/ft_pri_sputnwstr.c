/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_sputnwstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 15:27:10 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/18 15:27:24 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pri_sputnwstr(char *str, const wchar_t *src, size_t len)
{
	int		i;
	size_t	n;

	i = 0;
	n = 0;
	while (n < len)
	{
		str += ft_sputwchar(str, src[i]);
		n += ft_pri_size_wchar(src[i]);
		i++;
	}
	return (i);
}
