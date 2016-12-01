/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:57:31 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/01 17:19:03 by etrobert         ###   ########.fr       */
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

void	ft_pri_print_opts(char *str, t_pri_opts *opts)
{
	if (opts->spec == PRI_STRING)
		ft_strcpy(str, opts->elem.v_str);
	else if (opts->spec == PRI_UINT)
		ft_sputull_dig(opts->elem.v_uint, opts->base, str, opts->size);
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
		ft_pri_print_opts(str, ptr);
		str += ptr->size;
		next = ptr->next_char;
		it = ft_hlist_it_next(it);
	}
	ft_pri_print_fmt(&str, fmt, next);
}
