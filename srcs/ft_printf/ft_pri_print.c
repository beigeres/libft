/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:57:31 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/14 11:55:06 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_pri_print_sign(char *str, t_pri_opts *opts)
{
	int	n;

	n = 0;
	if (opts->elem.v_int < 0)
	{
		str[0] = '-';
		n++;
	}
	else if (opts->sign == PRI_SSIGN_ON)
	{
		str[0] = '+';
		n++;
	}
	else if (opts->sign == PRI_SSPACE)
	{
		str[0] = ' ';
		n++;
	}
	ft_sputuintmax_dig(ft_intmaxabs(opts->elem.v_int), opts->base,
			str + n, opts->little_size - n);
}

void		ft_pri_print_fmt_opts(char *str, t_pri_opts *opts)
{
	if (!ft_pri_valid_format(opts->elem.v_fmt))
		return ;
	ft_strcpy(str, "\033[");
	ft_sputuintmax_dig(opts->elem.v_fmt, opts->base, str + 2,
			opts->little_size - 3);
	str[opts->little_size - 1] = 'm';
}

static void	ft_pri_print_opts(char *str, t_pri_opts *opts)
{
	if (opts->spec == PRI_STRING)
		ft_pri_print_str(str, opts);
	else if (opts->spec == PRI_UINT || opts->spec == PRI_BIN)
		ft_sputuintmax_dig(opts->elem.v_uint,
				opts->base, str, opts->little_size);
	else if (opts->spec == PRI_HEXA || opts->spec == PRI_HEXA_MAJ ||
			opts->spec == PRI_OCTAL || opts->spec == PRI_POINTER)
		ft_pri_print_pref(str, opts);
	else if (opts->spec == PRI_INT)
		ft_pri_print_sign(str, opts);
	else if (opts->spec == PRI_PERCENT)
		*str = '%';
	else if (opts->spec == PRI_CHAR)
		*str = opts->elem.v_char;
	else if (opts->spec == PRI_WCHAR)
		ft_sputwchar(str, opts->elem.v_wchar);
	else if (opts->spec == PRI_WSTRING)
		ft_pri_print_wstr(str, opts);
	else if (opts->spec == PRI_FMT)
		ft_pri_print_fmt_opts(str, opts);
}

static void	ft_pri_print_width(char *str, t_pri_opts *opts)
{
	if (opts->left_justify)
	{
		ft_pri_print_opts(str, opts);
		ft_memset(str + opts->little_size, ' ', opts->size - opts->little_size);
	}
	else
	{
		ft_memset(str, opts->width_char, opts->size - opts->little_size);
		ft_pri_print_opts(str + opts->size - opts->little_size, opts);
	}
}

void		ft_pri_print(char *str, const char *fmt, t_hlist *opts)
{
	int			next;
	t_hlist_it	it;
	t_pri_opts	*ptr;

	next = 0;
	it = ft_hlist_it_first(opts);
	while (!ft_hlist_it_end(it))
	{
		ft_pri_print_fmt(&str, fmt, next);
		ptr = (t_pri_opts *)ft_hlist_it_get(it);
		ft_pri_print_width(str, ptr);
		str += ptr->size;
		next = ptr->next_char;
		it = ft_hlist_it_next(it);
	}
	ft_pri_print_fmt(&str, fmt, next);
}
