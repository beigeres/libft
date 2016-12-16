/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_fmt_fct_ox.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:20:01 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/08 15:23:43 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pri_fmt_o(t_pri_opts *opts, va_list ap)
{
	opts->base = ft_base_new("01234567", 8);
	ft_pri_fmt_unsigned(opts, ap);
	opts->spec = PRI_OCTAL;
}

void	ft_pri_fmt_o_maj(t_pri_opts *opts, va_list ap)
{
	opts->base = ft_base_new("01234567", 8);
	opts->elem.v_uint = (uintmax_t)va_arg(ap, long int);
	opts->spec = PRI_OCTAL;
}

void	ft_pri_fmt_x(t_pri_opts *opts, va_list ap)
{
	opts->base = ft_base_new("0123456789abcdef", 16);
	ft_pri_fmt_unsigned(opts, ap);
	opts->spec = PRI_HEXA;
}

void	ft_pri_fmt_x_maj(t_pri_opts *opts, va_list ap)
{
	opts->base = ft_base_new("0123456789ABCDEF", 16);
	ft_pri_fmt_unsigned(opts, ap);
	opts->spec = PRI_HEXA_MAJ;
}

void	ft_pri_fmt_p(t_pri_opts *opts, va_list ap)
{
	opts->base = ft_base_new("0123456789abcdef", 16);
	opts->elem.v_uint = (uintmax_t)va_arg(ap, void *);
	opts->sharp = TRUE;
	opts->spec = PRI_POINTER;
}
