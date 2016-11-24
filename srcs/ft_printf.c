/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:59:21 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/24 19:12:33 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_pri_set_opts_default(t_pri_opts *opt)
{
	opt->left_justify = FALSE;
	opt->sign = DEFAULT;
	opt->sharp = FALSE;
	opt->zero = FALSE;
	opt->width = 0;
	opt->precision = -1;
	opt->spec = PRI_INT;
}

unsigned int	ft_pri_ull_size_prec(unsigned long long int n,
		const t_pri_opts *opts)
{
	return (ft_umax(ft_ull_digits_base(n, opts->base->size), opts->precision));
}

/*
** Computes the size of the element with the sign
** Must only be called with signed integers
*/

unsigned int	ft_pri_size_sign(const t_pri_opts *opts)
{
	return (ft_pri_ull_size_prec(ft_llabs(opts->elem.v_ll), opts) +
			((opts->elem.v_ll < 0 || opts->sign == SIGN_ON ||
			opts->sign == SPACE) ? 1 : 0));
}

/*
** Computes the size of the element with the prefix
** Must only be called with octal hexa or hexa_maj
*/

unsigned int	ft_pri_size_pref(const t_pri_opts *opts)
{
	unsigned int	add;

	add = 0;
	if (opts->sharp && opts->elem.v_ull != 0)
	{
		if (opts->spec == PRI_OCTAL)
			add = 1;
		else if (opts->spec == PRI_HEXA || opts->spec == PRI_HEXA_MAJ)
			add = 2;
	}
	return (add + ft_pri_ull_size_prec(opts->elem.v_ull, opts));
}

unsigned int	ft_pri_size_width(const t_pri_opts *opts)
{
	unsigned int	ret;

	if (opts->spec == PRI_OCTAL || opts->spec == PRI_HEXA ||
			opts->spec == PRI_HEXA_MAJ)
		ret = ft_pri_size_pref(opts);
	else if (opts->spec == PRI_INT)
		ret = ft_pri_size_sign(opts);
	else
		ret = ft_pri_ull_size_prec(opts->elem.v_ull, opts);
	return (ft_umax(ret, opts->width));
}
