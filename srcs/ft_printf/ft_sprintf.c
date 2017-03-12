/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 20:08:58 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/12 20:09:19 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_sprintf(char *str, const char *fmt, ...)
{
	va_list		ap;
	int			n;

	va_start(ap, fmt);
	n = ft_vsprintf(str, fmt, ap);
	va_end(ap);
	return (n);
}
