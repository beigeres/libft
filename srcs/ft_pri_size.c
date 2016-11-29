/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:37:58 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/28 17:45:00 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_pri_uint_size_prec(uintmax_t n, const t_pri_opts *opts)
{
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
			((opts->elem.v_int < 0 || opts->sign == PRI_SIGN_ON ||
			  opts->sign == PRI_SPACE) ? 1 : 0));
}

/*
** Computes the size of the element with the prefix
** Must only be called with octal hexa or hexa_maj
*/

unsigned int	ft_pri_size_pref(const t_pri_opts *opts)
{
	unsigned int	add;

	add = 0;
	if (opts->sharp && opts->elem.v_uint != 0)
	{
		if (opts->spec == PRI_OCTAL)
			add = 1;
		else if (opts->spec == PRI_HEXA || opts->spec == PRI_HEXA_MAJ)
			add = 2;
	}
	return (add + ft_pri_uint_size_prec(opts->elem.v_uint, opts));
}

/*
** Computes the size of the element according to the width parameter
*/

unsigned int	ft_pri_size_width(const t_pri_opts *opts)
{
	unsigned int	ret;

	if (opts->spec == PRI_OCTAL || opts->spec == PRI_HEXA ||
			opts->spec == PRI_HEXA_MAJ)
		ret = ft_pri_size_pref(opts);
	else if (opts->spec == PRI_INT)
		ret = ft_pri_size_sign(opts);
	else
		ret = ft_pri_uint_size_prec(opts->elem.v_uint, opts);
	return (ft_intmaxmax(ret, opts->width));
}
