/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_fmt_fct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:00:37 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/04 18:13:49 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_pri_fmt_unsigned(t_pri_opts *opts, va_list ap)
{
	if (opts->length == PRI_HH)
		opts->elem.v_uint = (uintmax_t)((unsigned char)va_arg(ap, unsigned int));
	else if (opts->length == PRI_H)
		opts->elem.v_uint = (uintmax_t)((unsigned short)va_arg(ap, unsigned int));
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
	static t_base	base = { 10, "0123456789" };

	opts->base = &base;
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


void	ft_pri_fmt_u(t_pri_opts *opts, va_list ap)
{
	static t_base	base = { 10, "0123456789" };

	opts->base = &base;
	ft_pri_fmt_unsigned(opts, ap);
	opts->spec = PRI_UINT;
}

void	ft_pri_fmt_u_maj(t_pri_opts *opts, va_list ap)
{
	opts->length = PRI_L;
	ft_pri_fmt_u(opts, ap);
}

void	ft_pri_fmt_b(t_pri_opts *opts, va_list ap)
{
	static t_base	base = { 2, "01" };

	opts->base = &base;
	ft_pri_fmt_unsigned(opts, ap);
	opts->spec = PRI_BIN;
}

void	ft_pri_fmt_o(t_pri_opts *opts, va_list ap)
{
	static t_base	base = { 8, "01234567" };

	opts->base = &base;
	ft_pri_fmt_unsigned(opts, ap);
	opts->spec = PRI_OCTAL;
}

static void	ft_pri_fmt_base_hex(t_pri_opts *opts)
{
	static t_base	base = { 16, "0123456789abcdef" };
	opts->base = &base;
}

void	ft_pri_fmt_x(t_pri_opts *opts, va_list ap)
{
	ft_pri_fmt_base_hex(opts);
	ft_pri_fmt_unsigned(opts, ap);
	opts->spec = PRI_HEXA;
}

void	ft_pri_fmt_x_maj(t_pri_opts *opts, va_list ap)
{
	static t_base	base = { 16, "0123456789ABCDEF" };
	opts->base = &base;
	ft_pri_fmt_unsigned(opts, ap);
	opts->spec = PRI_HEXA_MAJ;
}

// wchar_t ? char ?
void	ft_pri_fmt_c(t_pri_opts *opts, va_list ap)
{
	if (opts->length == PRI_L)
		opts->elem.v_char = va_arg(ap, wint_t);
	else
		opts->elem.v_char = va_arg(ap, int);
	opts->spec = PRI_CHAR;
}

void	ft_pri_fmt_s(t_pri_opts *opts, va_list ap)
{
	if (opts->length == PRI_L)
	{
		opts->elem.v_wstr = va_arg(ap, wchar_t *);
		opts->spec = PRI_WSTRING;
	}
	else
	{
		opts->elem.v_str = va_arg(ap, char *);
		opts->spec = PRI_STRING;
	}
}

void	ft_pri_fmt_p(t_pri_opts *opts, va_list ap)
{
	ft_pri_fmt_base_hex(opts);
	opts->elem.v_uint = (uintmax_t)va_arg(ap, void *);
	opts->sharp = TRUE;
	opts->spec = PRI_POINTER;
}

void	ft_pri_fmt_percent(t_pri_opts *opts)
{
	opts->spec = PRI_PERCENT;
}
