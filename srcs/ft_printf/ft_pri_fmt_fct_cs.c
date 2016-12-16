/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_fmt_fct_cs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:22:33 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/08 15:27:16 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_pri_fmt_c(t_pri_opts *opts, va_list ap)
{
	if (opts->length == PRI_L)
		ft_pri_fmt_c_maj(opts, ap);
	else
	{
		opts->spec = PRI_CHAR;
		opts->elem.v_char = va_arg(ap, int);
	}
}

void		ft_pri_fmt_c_maj(t_pri_opts *opts, va_list ap)
{
	opts->spec = PRI_WCHAR;
	opts->elem.v_wchar = (wchar_t)va_arg(ap, wint_t);
}

void		ft_pri_fmt_s(t_pri_opts *opts, va_list ap)
{
	if (opts->length == PRI_L)
		ft_pri_fmt_s_maj(opts, ap);
	else
	{
		opts->elem.v_str = va_arg(ap, char *);
		opts->spec = PRI_STRING;
	}
}

void		ft_pri_fmt_s_maj(t_pri_opts *opts, va_list ap)
{
	opts->elem.v_wstr = va_arg(ap, wchar_t *);
	opts->spec = PRI_WSTRING;
}
