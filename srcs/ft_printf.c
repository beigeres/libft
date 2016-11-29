/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:59:21 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/29 13:53:26 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		n;

	va_start(ap, fmt);
	n = ft_vprintf(fmt, ap);
	va_end(ap);
	return (n);
}

int		ft_sprintf(char *str, const char *fmt, ...)
{
	va_list	ap;
	int		n;

	va_start(ap, fmt);
	n = ft_vsprintf(str, fmt, ap);
	va_end(ap);
	return (n);
}

int		ft_asprintf(char **ret, const char *fmt, ...)
{
	va_list	ap;
	int		n;

	va_start(ap, fmt);
	n = ft_vasprintf(ret, fmt, ap);
	va_end(ap);
	return (n);
}

int		ft_dprintf(int fd, const char *fmt, ...)
{
	va_list ap;
	int		n;

	va_start(ap, fmt);
	n = ft_vdprintf(fd, fmt, ap);
	va_end(ap);
	return (n);
}
