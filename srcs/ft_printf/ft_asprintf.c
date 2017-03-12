/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 20:08:09 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/12 20:18:25 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_asprintf(char **ret, const char *fmt, ...)
{
	va_list		ap;
	int			n;

	if (ret == NULL)
		return (-1);
	va_start(ap, fmt);
	n = ft_vasprintf(ret, fmt, ap);
	va_end(ap);
	return (n);
}
