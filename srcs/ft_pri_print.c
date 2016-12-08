/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:57:31 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/08 12:17:48 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_pri_print_fmt(char **str, const char *fmt, int i)
{
	while (fmt[i] != '\0' && fmt[i] != '%')
	{
		**str = fmt[i];
		i++;
		(*str)++;
	}
}

static void	ft_pri_print_pref(char *str, t_pri_opts *opts)
{
	int	n;

	n = 0;
	if (opts->sharp)
	{
		if (opts->spec == PRI_OCTAL)
		{
			str[0] = '0';
			n++;
		}
		else if (opts->spec == PRI_POINTER || opts->elem.v_uint != 0)
		{
			str[0] = '0';
			if (opts->spec == PRI_POINTER || opts->spec == PRI_HEXA)
				str[1] = 'x';
			else if (opts->spec == PRI_HEXA_MAJ)
				str[1] = 'X';
			n += 2;
		}
	}
	ft_sputuintmax_dig(opts->elem.v_uint, opts->base, str + n,
			opts->little_size - n);
}

void	ft_pri_print_str(char *str, t_pri_opts *opts)
{
	if (opts->elem.v_str == NULL)
		ft_strcpy(str, "(null)");
	else
		ft_strncpy(str, opts->elem.v_str, opts->little_size);
}

void	ft_pri_print_wstr(char *str, t_pri_opts *opts)
{
	if (opts->elem.v_wstr == NULL)
		ft_strcpy(str, "(null)");
	else
		ft_sputwstr(str, opts->elem.v_wstr);
}

void	ft_pri_print_sign(char *str, t_pri_opts *opts)
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

void	ft_pri_print_opts(char *str, t_pri_opts *opts)
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
}

void	ft_pri_print_width(char *str, t_pri_opts *opts)
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

void	ft_pri_print(char *str, const char *fmt, t_hlist *opts)
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
