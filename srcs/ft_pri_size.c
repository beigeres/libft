/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:37:58 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/04 20:44:44 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_pri_uint_size_prec(uintmax_t n, const t_pri_opts *opts)
{
	if (opts->prec_set && opts->precision == 0 && n == 0)
		return (0);
	return (ft_intmaxmax(ft_uintmax_digits_base(n, opts->base->size),
				opts->precision));
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
		if (opts->spec == PRI_OCTAL)
			add = 1;
		else if (opts->spec == PRI_POINTER || 
				(opts->elem.v_uint != 0 &&
				 (opts->spec == PRI_HEXA || opts->spec == PRI_HEXA_MAJ)))
			add = 2;
	}
	return (add + ft_pri_uint_size_prec(opts->elem.v_uint, opts));
}

/*
** Computes the size of the element according to the width parameter
*/

unsigned int	ft_pri_size_little_size(const t_pri_opts *opts)
{
	if (opts->spec == PRI_OCTAL || opts->spec == PRI_HEXA ||
			opts->spec == PRI_HEXA_MAJ || opts->spec == PRI_POINTER)
		return (ft_pri_size_pref(opts));
	else if (opts->spec == PRI_INT)
		return (ft_pri_size_sign(opts));
	else if (opts->spec == PRI_UINT || opts->spec == PRI_BIN)
		return (ft_pri_uint_size_prec(opts->elem.v_uint, opts));
	else if (opts->spec == PRI_STRING)
	{
		if (opts->elem.v_str == NULL)
			return (6);
		if (opts->prec_set)
			return (ft_umin(opts->precision, ft_strlen(opts->elem.v_str)));
		return (ft_strlen(opts->elem.v_str));
	}
	else if (opts->spec == PRI_CHAR || opts->spec == PRI_PERCENT)
		return (1);
	return (0);
}

//ne pas faire le trick pour lkes chaines et char juste les nombres
//ATTENTION DEGUEU DEGUEU
unsigned int	ft_pri_size_width(t_pri_opts *opts)
{
	if (opts->width_char == '0' && !opts->left_justify && opts->width > opts->little_size)
	{
		opts->precision += opts->width - opts->little_size;
		opts->little_size += opts->width - opts->little_size;
	}
	return (ft_umax(opts->little_size, opts->width));
}
