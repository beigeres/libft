/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_fmt_fct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:00:37 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/08 15:28:14 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pri_fmt_d(t_pri_opts *opts, va_list ap)
{
	opts->base = ft_base_new("0123456789", 10);
	opts->spec = PRI_INT;
	if (opts->length == PRI_HH)
		opts->elem.v_int = (intmax_t)((signed char)va_arg(ap, int));
	else if (opts->length == PRI_H)
		opts->elem.v_int = (intmax_t)((short int)va_arg(ap, int));
	else if (opts->length == PRI_L)
		opts->elem.v_int = (intmax_t)va_arg(ap, long int);
	else if (opts->length == PRI_LL)
		opts->elem.v_int = (intmax_t)va_arg(ap, long long int);
	else if (opts->length == PRI_J)
		opts->elem.v_int = (intmax_t)va_arg(ap, intmax_t);
	else if (opts->length == PRI_Z)
		opts->elem.v_int = (intmax_t)va_arg(ap, size_t);
	else if (opts->length == PRI_T)
		opts->elem.v_int = (intmax_t)va_arg(ap, ptrdiff_t);
	else
		opts->elem.v_int = (intmax_t)va_arg(ap, int);
}

void	ft_pri_fmt_d_maj(t_pri_opts *opts, va_list ap)
{
	opts->length = PRI_L;
	ft_pri_fmt_d(opts, ap);
}

void	ft_pri_fmt_b(t_pri_opts *opts, va_list ap)
{
	opts->base = ft_base_new("01", 2);
	ft_pri_fmt_unsigned(opts, ap);
	opts->spec = PRI_BIN;
}

void	ft_pri_fmt_percent(t_pri_opts *opts)
{
	opts->spec = PRI_PERCENT;
}
