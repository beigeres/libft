/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 20:07:11 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/12 20:34:05 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_dprintf(int fd, const char *fmt, ...)
{
	va_list		ap;
	int			n;

	va_start(ap, fmt);
	n = ft_vdprintf(fd, fmt, ap);
	va_end(ap);
	return (n);
}
