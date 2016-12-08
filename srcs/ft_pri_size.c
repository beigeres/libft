/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:37:58 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/08 12:15:19 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_pri_uint_size_digs(uintmax_t n, const t_pri_opts *opts)
{
	if (opts->prec_set && opts->precision == 0 && n == 0)
		return (0);
	return (ft_uintmax_digits_base(n, opts->base->size));
}

static unsigned int	ft_pri_uint_size_prec(uintmax_t n, const t_pri_opts *opts)
{
	return (ft_intmaxmax(ft_pri_uint_size_digs(n, opts), opts->precision));
}

static unsigned int	ft_pri_octal_prec(const t_pri_opts *opts)
{
	unsigned int	n;

	n = ft_pri_uint_size_digs(opts->elem.v_uint, opts);
	if (opts->sharp && (opts->elem.v_uint != 0 || opts->prec_set))
		++n;
	return (ft_intmaxmax(n, opts->precision));
}

/*
** Computes the size of the element with the sign
** Must only be called with signed integers
*/

unsigned int	ft_pri_size_sign(const t_pri_opts *opts)
{
	return (ft_pri_uint_size_prec(ft_intmaxabs(opts->elem.v_int), opts) +
			((opts->elem.v_int < 0 || opts->sign == PRI_SSIGN_ON ||
			opts->sign == PRI_SSPACE) ? 1 : 0));
}

/*
** Computes the size of the element with the prefix
** Must only be called with octal hexa or hexa_maj
*/

static unsigned int	ft_pri_size_pref(const t_pri_opts *opts)
{
	unsigned int	add;

	add = 0;
	if (opts->sharp)
	{
		if (opts->spec == PRI_POINTER ||
				(opts->elem.v_uint != 0 &&
				(opts->spec == PRI_HEXA || opts->spec == PRI_HEXA_MAJ)))
			add = 2;
	}
	return (add + ft_pri_uint_size_prec(opts->elem.v_uint, opts));
}

unsigned int	ft_pri_wlen(const t_pri_opts *opts)
{
	unsigned int	i;
	unsigned int	n;
	unsigned int	inc;

	n = 0;
	inc = 0;
	i = 0;
	while (opts->elem.v_wstr[i] != '\0')
	{
		inc = ft_wchar_dig(opts->elem.v_wstr[i]);
		if (opts->prec_set && n + inc > opts->precision)
			return (n);
		n += inc;
		i++;
	}
	return (n);
}

unsigned int	ft_pri_size_wstr(const t_pri_opts *opts)
{
	if (opts->elem.v_wstr == NULL)
	{
		if (opts->prec_set)
			return (ft_umin(opts->precision, 6));
		else
			return (6);
	}
	else
		return (ft_pri_wlen(opts));
}

unsigned int	ft_pri_size_str(const t_pri_opts *opts)
{
	unsigned int	n;

	n = (opts->elem.v_str == NULL) ? 6 : ft_strlen(opts->elem.v_str);
	if (opts->prec_set)
		return (ft_umin(opts->precision, n));
	return (n);
}

/*
** Computes the size of the element according to the width parameter
*/

unsigned int	ft_pri_size_little_size(const t_pri_opts *opts)
{
	if (opts->spec == PRI_OCTAL)
		return (ft_pri_octal_prec(opts));
	else if (opts->spec == PRI_HEXA || opts->spec == PRI_HEXA_MAJ ||
			opts->spec == PRI_POINTER)
		return (ft_pri_size_pref(opts));
	else if (opts->spec == PRI_INT)
		return (ft_pri_size_sign(opts));
	else if (opts->spec == PRI_UINT || opts->spec == PRI_BIN)
		return (ft_pri_uint_size_prec(opts->elem.v_uint, opts));
	else if (opts->spec == PRI_STRING)
		return (ft_pri_size_str(opts));
	else if (opts->spec == PRI_WSTRING)
		return (ft_pri_size_wstr(opts));
	else if (opts->spec == PRI_WCHAR)
		return (ft_wchar_dig(opts->elem.v_wchar));
	else if (opts->spec == PRI_CHAR || opts->spec == PRI_PERCENT)
		return (1);
	return (0);
}

t_bool	ft_pri_is_number(const t_pri_opts *opts)
{
	return (opts->spec == PRI_INT || opts->spec == PRI_UINT ||
			opts->spec == PRI_OCTAL || opts->spec == PRI_HEXA ||
			opts->spec == PRI_HEXA || opts->spec == PRI_HEXA_MAJ ||
			opts->spec == PRI_BIN || opts->spec == PRI_POINTER);
}

unsigned int	ft_pri_size_width(t_pri_opts *opts)
{
	if (opts->width_char == '0' && !opts->left_justify &&
			opts->width > opts->little_size && ft_pri_is_number(opts))
	{
		opts->precision += opts->width - opts->little_size;
		opts->little_size += opts->width - opts->little_size;
	}
	return (ft_umax(opts->little_size, opts->width));
}
