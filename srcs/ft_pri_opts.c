/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_opts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:36:51 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/28 17:36:57 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pri_opts		*ft_pri_opts_new(void)
{
	t_pri_opts	*opts;

	if ((opts = malloc(sizeof(*opts))) == NULL)
		return (NULL);
	ft_pri_set_opts_default(opts);
	return (opts);
}

void			ft_pri_set_opts_default(t_pri_opts *opt)
{
	opt->left_justify = FALSE;
	opt->sign = PRI_DEFAULT;
	opt->sharp = FALSE;
	opt->zero = FALSE;
	opt->width = 0;
	opt->precision = -1;
	opt->spec = PRI_INT;
}

