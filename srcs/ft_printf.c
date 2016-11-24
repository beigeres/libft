/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:59:21 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/24 15:42:53 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pri_set_opts_default(t_pri_opts *opt)
{
	opt->left_justify = FALSE;
	opt->sign = DEFAULT;
	opt->sharp = FALSE;
	opt->zero = FALSE;
	opt->min_size = 0;
	opt->precision = -1;
	opt->sp = INT;
}

unsigned int	ft_pri_size_prec(long long int n, const t_pri_opts *opts)
{
	return (ft_umax(ft_ull_digits_base(ft_llabs(n), opts->base->size),
				opts->precision));
}
