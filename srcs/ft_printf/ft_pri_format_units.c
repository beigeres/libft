/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_format_units.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:00:41 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/12 20:08:30 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool		ft_pri_format_unit(const char *fmt,
		va_list ap, unsigned int *i, t_pri_opts *opts)
{
	if (ft_pri_format_spec(fmt[*i], opts, ap))
	{
		++(*i);
		return (TRUE);
	}
	if (!ft_pri_format_flags(fmt[*i], opts) &&
			!ft_pri_format_length(fmt[*i], opts))
	{
		opts->spec = PRI_CHAR;
		opts->elem.v_char = fmt[*i];
		++(*i);
		return (TRUE);
	}
	return (FALSE);
}
