/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_sputwstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 15:21:59 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/18 15:22:01 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pri_sputwstr(char *str, const wchar_t *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		str += ft_sputwchar(str, src[i]);
		i++;
	}
	return (i);
}
