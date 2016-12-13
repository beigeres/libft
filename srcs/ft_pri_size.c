/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:37:58 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/13 20:04:07 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_pri_wlen(const t_pri_opts *opts)
{
	unsigned int	i;
	unsigned int	n;
	int				inc;

	n = 0;
	inc = 0;
	i = 0;
	while (opts->elem.v_wstr[i] != '\0')
	{
		if ((inc = ft_pri_size_wchar(opts->elem.v_wstr[i])) < 0)
			return (-1);
		if (opts->prec_set && n + inc > opts->precision)
			return (n);
		n += inc;
		i++;
	}
	return (n);
}

unsigned int	ft_pri_size_wstr(const t_pri_opts *opts)
{
	if (opts->elem.v_wstr == NULL)
	{
		if (opts->prec_set)
			return (ft_umin(opts->precision, 6));
		else
			return (6);
	}
	else
		return (ft_pri_wlen(opts));
}

unsigned int	ft_pri_size_str(const t_pri_opts *opts)
{
	unsigned int	n;

	n = (opts->elem.v_str == NULL) ? 6 : ft_strlen(opts->elem.v_str);
	if (opts->prec_set)
		return (ft_umin(opts->precision, n));
	return (n);
}

/*
** Computes the size of the element according to the width parameter
*/

int				ft_pri_size_little_size(const t_pri_opts *opts)
{
	if (opts->spec == PRI_OCTAL)
		return (ft_pri_octal_prec(opts));
	else if (opts->spec == PRI_HEXA || opts->spec == PRI_HEXA_MAJ ||
			opts->spec == PRI_POINTER)
		return (ft_pri_size_pref(opts));
	else if (opts->spec == PRI_INT)
		return (ft_pri_size_sign(opts));
	else if (opts->spec == PRI_UINT || opts->spec == PRI_BIN)
		return (ft_pri_uint_size_prec(opts->elem.v_uint, opts));
	else if (opts->spec == PRI_STRING)
		return (ft_pri_size_str(opts));
	else if (opts->spec == PRI_WSTRING)
		return (ft_pri_size_wstr(opts));
	else if (opts->spec == PRI_WCHAR)
		return (ft_pri_size_wchar(opts->elem.v_wchar));
	else if (opts->spec == PRI_CHAR || opts->spec == PRI_PERCENT)
		return (1);
	return (0);
}
