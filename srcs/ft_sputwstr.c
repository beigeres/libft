/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sputwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:13:59 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/07 16:28:06 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wchar.h"

size_t	ft_sputwstr(char *str, const wchar_t *src)
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
