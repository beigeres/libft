/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:53:01 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/04 20:41:52 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bool		ft_pri_format_flags(char fmt, t_pri_opts *opts)
{
	if (fmt == '-')
		opts->left_justify = TRUE;
	else if (fmt == '+')
		opts->sign = PRI_SSIGN_ON;
	else if (fmt == ' ')
	{
		if (opts->sign != PRI_SSIGN_ON)
			opts->sign = PRI_SSPACE;
	}
	else if (fmt == '#')
		opts->sharp = TRUE;
	else if (fmt == '0')
		opts->width_char = '0';
	else
		return (FALSE);
	return (TRUE);
}

static t_bool		ft_pri_format_spec(char fmt, t_pri_opts *opts, va_list ap)
{
	if (fmt == 'd' || fmt == 'i')
		ft_pri_fmt_d(opts, ap);
	else if (fmt == 'u')
		ft_pri_fmt_u(opts, ap);
	else if (fmt == 'U')
		ft_pri_fmt_u_maj(opts, ap);
	else if (fmt == 'b')
		ft_pri_fmt_b(opts, ap);
	else if (fmt == 'o')
		ft_pri_fmt_o(opts, ap);
	else if (fmt == 'x')
		ft_pri_fmt_x(opts, ap);
	else if (fmt == 'X')
		ft_pri_fmt_x_maj(opts, ap);
	else if (fmt == 'c')
		ft_pri_fmt_c(opts, ap);
	else if (fmt == 's')
		ft_pri_fmt_s(opts, ap);
	else if (fmt == 'p')
		ft_pri_fmt_p(opts, ap);
	else if (fmt == '%')
		ft_pri_fmt_percent(opts);
	else
		return (FALSE);
	return (TRUE);
}

static t_bool		ft_pri_format_length(char fmt, t_pri_opts *opts)
{
	if (fmt == 'h')
	{
		if (opts->length == PRI_H)
			opts->length = PRI_HH;
		else
			opts->length = PRI_H;
	}
	else if (fmt == 'l')
	{
		if (opts->length == PRI_L)
			opts->length = PRI_LL;
		else
			opts->length = PRI_L;
	}
	else if (fmt == 'j')
		opts->length = PRI_J;
	else if (fmt == 'z')
		opts->length = PRI_Z;
	else if (fmt == 't')
		opts->length = PRI_T;
	else
		return (FALSE);
	return (TRUE);
}

static t_bool		ft_pri_format_digit(char fmt, t_pri_opts *opts, t_pri_mode *mode)
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

//0 causing problem : is it part of a number or the 0 flag ?
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
		{
			mode = PRI_MPREC;
			opts->prec_set = TRUE;
			opts->width_char = ' ';
			opts->precision = 0;
		}
		else if (!ft_pri_format_digit(fmt[*i], opts, &mode))
		{
			mode = PRI_MDEFAULT;
			if (ft_pri_format_spec(fmt[*i], opts, ap))
			{
				return (opts);
			}
			if (!ft_pri_format_flags(fmt[*i], opts) &&
					!ft_pri_format_length(fmt[*i], opts))
			{
				free(opts);
				return (NULL);
			}
		}
		(*i)++;
	}
	free(opts);
	return (NULL);
}

int						ft_pri_decrypt_format(const char *fmt, va_list ap, t_hlist *opts)
{
	unsigned int	n;
	unsigned int	i;
	t_pri_opts		*elem;

	n = 0;
	i = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			i++;
			if ((elem = ft_pri_format(fmt, ap, &i)) != NULL)
			{
				if (!ft_hlist_push_back(opts, elem))
					return (-1);
				elem->little_size = ft_pri_size_little_size(elem);
				elem->size = ft_pri_size_width(elem);
				elem->next_char = i + 1;
				n += elem->size;
				i++;
			}
		}
		else
		{
			n++;
			i++;
		}
	}
	return (n);
}
