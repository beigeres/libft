/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_fmt_fct_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:24:42 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/08 15:28:55 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pri_fmt_unsigned(t_pri_opts *opts, va_list ap)
{
	if (opts->length == PRI_HH)
		opts->elem.v_uint =
			(uintmax_t)((unsigned char)va_arg(ap, unsigned int));
	else if (opts->length == PRI_H)
		opts->elem.v_uint =
			(uintmax_t)((unsigned short)va_arg(ap, unsigned int));
	else if (opts->length == PRI_L)
		opts->elem.v_uint = (uintmax_t)va_arg(ap, unsigned long int);
	else if (opts->length == PRI_LL)
		opts->elem.v_uint = (uintmax_t)va_arg(ap, unsigned long long int);
	else if (opts->length == PRI_J)
		opts->elem.v_uint = (uintmax_t)va_arg(ap, uintmax_t);
	else if (opts->length == PRI_Z)
		opts->elem.v_uint = (uintmax_t)va_arg(ap, size_t);
	else if (opts->length == PRI_T)
		opts->elem.v_uint = (uintmax_t)va_arg(ap, ptrdiff_t);
	else
		opts->elem.v_uint = (uintmax_t)va_arg(ap, unsigned int);
}

void	ft_pri_fmt_u(t_pri_opts *opts, va_list ap)
{
	opts->base = ft_base_new("0123456789", 10);
	ft_pri_fmt_unsigned(opts, ap);
	opts->spec = PRI_UINT;
}

void	ft_pri_fmt_u_maj(t_pri_opts *opts, va_list ap)
{
	opts->base = ft_base_new("0123456789", 10);
	opts->length = PRI_L;
	opts->elem.v_uint = (uintmax_t)va_arg(ap, long int);
	opts->spec = PRI_UINT;
}
