/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_format_units.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:00:41 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/09 11:36:49 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool		ft_pri_format_unit(const char *fmt,
		va_list ap, unsigned int *i, t_pri_opts *opts)
{
	if (ft_pri_format_spec(fmt[*i], opts, ap))
	{
		++(*i);
		return (true);
	}
	if (!ft_pri_format_flags(fmt[*i], opts) &&
			!ft_pri_format_length(fmt[*i], opts))
	{
		opts->spec = PRI_CHAR;
		opts->elem.v_char = fmt[*i];
		++(*i);
		return (true);
	}
	return (false);
}
