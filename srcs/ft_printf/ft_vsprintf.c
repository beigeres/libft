/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 20:19:08 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/12 20:22:44 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_vsprintf(char *str, const char *fmt, va_list ap)
{
	t_hlist		*opts;
	int			n;

	if (str == NULL)
		return (-1);
	if ((opts = ft_hlist_new()) == NULL)
		return (-1);
	if ((n = ft_pri_decrypt_format(fmt, ap, opts)) < 0)
	{
		ft_hlist_delete(opts);
		return (-1);
	}
	ft_pri_print(str, fmt, opts);
	ft_hlist_apply(opts, (t_f_action) & ft_pri_opts_delete);
	ft_hlist_delete(opts);
	return (n);
}
