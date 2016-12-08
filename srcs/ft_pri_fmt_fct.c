/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_fmt_fct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:00:37 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/08 12:13:26 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_pri_fmt_unsigned(t_pri_opts *opts, va_list ap)
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

void	ft_pri_fmt_b(t_pri_opts *opts, va_list ap)
{
	opts->base = ft_base_new("01", 2);
	ft_pri_fmt_unsigned(opts, ap);
	opts->spec = PRI_BIN;
}

void	ft_pri_fmt_o(t_pri_opts *opts, va_list ap)
{
	opts->base = ft_base_new("01234567", 8);
	ft_pri_fmt_unsigned(opts, ap);
	opts->spec = PRI_OCTAL;
}

void	ft_pri_fmt_o_maj(t_pri_opts *opts, va_list ap)
{
	opts->base = ft_base_new("01234567", 8);
	opts->elem.v_uint = (uintmax_t)va_arg(ap, long int);
	opts->spec = PRI_OCTAL;
}

void	ft_pri_fmt_x(t_pri_opts *opts, va_list ap)
{
	opts->base = ft_base_new("0123456789abcdef", 16);
	ft_pri_fmt_unsigned(opts, ap);
	opts->spec = PRI_HEXA;
}

void	ft_pri_fmt_x_maj(t_pri_opts *opts, va_list ap)
{
	opts->base = ft_base_new("0123456789ABCDEF", 16);
	ft_pri_fmt_unsigned(opts, ap);
	opts->spec = PRI_HEXA_MAJ;
}

void	ft_pri_fmt_c(t_pri_opts *opts, va_list ap)
{
	if (opts->length == PRI_L)
		ft_pri_fmt_c_maj(opts, ap);
	else
	{
		opts->spec = PRI_CHAR;
		opts->elem.v_char = va_arg(ap, int);
	}
}

void	ft_pri_fmt_c_maj(t_pri_opts *opts, va_list ap)
{
	opts->spec = PRI_WCHAR;
	opts->elem.v_wchar = (wchar_t)va_arg(ap, wint_t);
}

void	ft_pri_fmt_s(t_pri_opts *opts, va_list ap)
{
	if (opts->length == PRI_L)
		ft_pri_fmt_s_maj(opts, ap);
	else
	{
		opts->elem.v_str = va_arg(ap, char *);
		opts->spec = PRI_STRING;
	}
}

void	ft_pri_fmt_s_maj(t_pri_opts *opts, va_list ap)
{
	opts->elem.v_wstr = va_arg(ap, wchar_t *);
	opts->spec = PRI_WSTRING;
}

void	ft_pri_fmt_p(t_pri_opts *opts, va_list ap)
{
	opts->base = ft_base_new("0123456789abcdef", 16);
	opts->elem.v_uint = (uintmax_t)va_arg(ap, void *);
	opts->sharp = TRUE;
	opts->spec = PRI_POINTER;
}

void	ft_pri_fmt_percent(t_pri_opts *opts)
{
	opts->spec = PRI_PERCENT;
}
