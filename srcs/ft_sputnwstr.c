/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sputnwstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 19:54:26 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/13 20:19:10 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wchar.h"

size_t	ft_sputnwstr(char *str, const wchar_t *src, size_t len)
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
