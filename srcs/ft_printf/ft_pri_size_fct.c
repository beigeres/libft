/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_size_fct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:52:33 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/08 18:00:32 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_pri_uint_size_digs(uintmax_t n, const t_pri_opts *opts)
{
	if (opts->prec_set && opts->precision == 0 && n == 0)
		return (0);
	return (ft_uintmax_digits_base(n, opts->base->size));
}

unsigned int	ft_pri_uint_size_prec(uintmax_t n, const t_pri_opts *opts)
{
	return (ft_intmaxmax(ft_pri_uint_size_digs(n, opts), opts->precision));
}

unsigned int	ft_pri_octal_prec(const t_pri_opts *opts)
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

unsigned int	ft_pri_size_pref(const t_pri_opts *opts)
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
