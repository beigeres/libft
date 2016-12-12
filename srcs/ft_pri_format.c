/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:53:01 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/11 19:16:14 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bool		ft_pri_format_digit(char fmt, t_pri_opts *opts,
		t_pri_mode *mode)
{
	if (!ft_isdigit(fmt))
		return (FALSE);
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
	*mode = PRI_MPREC;
	opts->prec_set = TRUE;
	opts->precision = 0;
}

static t_pri_opts	*ft_pri_format(const char *fmt, va_list ap, unsigned int *i)
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

t_bool				ft_pri_decrypt_format_sstuff(t_pri_opts *elem,
		unsigned int *n)
{
	int	k;

	if ((k = ft_pri_size_little_size(elem)) < 0)
		return (FALSE);
	elem->little_size = k;
	if (elem->width_char == '0' && elem->prec_set &&
			ft_pri_is_number(elem))
		elem->width_char = ' ';
	elem->size = ft_pri_size_width(elem);
	*n += elem->size;
	return (TRUE);
}

int					ft_pri_decrypt_format(const char *fmt, va_list ap,
		t_hlist *opts)
{
	unsigned int	n;
	unsigned int	i;
	t_pri_opts		*elem;

	n = 0;
	i = 0;
	while (fmt[i++] != '\0')
	{
		if (fmt[i - 1] == '%')
		{
			if ((elem = ft_pri_format(fmt, ap, &i)) != NULL)
			{
				if (!ft_hlist_push_back(opts, elem))
					return (-1);
				if (!ft_pri_decrypt_format_sstuff(elem, &n))
					return (-1);
				elem->next_char = i;
			}
		}
		else
			n++;
	}
	return (n);
}
