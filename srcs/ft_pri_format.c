/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:53:01 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/12 20:30:30 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bool		ft_pri_format_digit(char fmt, t_pri_opts *opts,
		t_pri_mode *mode)
{
	if (!ft_isdigit(fmt))
		return (FALSE);
	if (*mode == PRI_MPREC_STARTING)
		*mode = PRI_MPREC;
	if (*mode == PRI_MPREC)
		opts->precision = opts->precision * 10 + fmt - '0';
	else if (*mode == PRI_MWIDTH)
		opts->width = opts->width * 10 + fmt - '0';
	else
	{
		opts->width = fmt - '0';
		*mode = PRI_MWIDTH;
	}
	return (TRUE);
}

static void			ft_pri_format_dot(t_pri_opts *opts, t_pri_mode *mode)
{
	*mode = PRI_MPREC_STARTING;
	opts->prec_set = TRUE;
	opts->precision = 0;
}

static void			ft_pri_format_star(t_pri_opts *opts,
		t_pri_mode *mode, va_list ap)
{
	int	n;

	if (*mode == PRI_MPREC_STARTING)
	{
		n = va_arg(ap, int);
		if (n < 0)
			opts->prec_set = FALSE;
		else
			opts->precision = n;
	}
	else
	{
		n = va_arg(ap, int);
		if (n < 0)
		{
			opts->left_justify = TRUE;
			opts->width = (unsigned int)-n;
		}
		else
			opts->width = (unsigned int)n;
	}
	*mode = PRI_MDEFAULT;
}

t_pri_opts			*ft_pri_format(const char *fmt, va_list ap, unsigned int *i)
{
	t_pri_opts	*opts;
	t_pri_mode	mode;

	mode = PRI_MDEFAULT;
	if ((opts = ft_pri_opts_new()) == NULL)
		return (NULL);
	while (fmt[*i] != '\0')
	{
		if (fmt[*i] == '0' && mode == PRI_MDEFAULT)
			opts->width_char = '0';
		else if (fmt[*i] == '*')
			ft_pri_format_star(opts, &mode, ap);
		else if (fmt[*i] == '.')
			ft_pri_format_dot(opts, &mode);
		else if (!ft_pri_format_digit(fmt[*i], opts, &mode))
		{
			mode = PRI_MDEFAULT;
			if (ft_pri_format_unit(fmt, ap, i, opts))
				return (opts);
		}
		++(*i);
	}
	free(opts);
	return (NULL);
}
