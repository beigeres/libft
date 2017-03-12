/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 20:25:08 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/12 20:25:54 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	char		*str;
	int			n;
	ssize_t		ret;

	if ((n = ft_vasprintf(&str, fmt, ap)) < 0)
		return (-1);
	ret = write(fd, str, n);
	free(str);
	if (ret < 0)
		return (ret);
	return (n);
}
