/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 20:24:14 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/12 20:33:16 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_vasprintf(char **ret, const char *fmt, va_list ap)
{
	t_hlist		*opts;
	int			n;

	if ((opts = ft_hlist_new()) == NULL)
		return (-1);
	if ((n = ft_pri_decrypt_format(fmt, ap, opts)) < 0)
	{
		ft_hlist_delete(opts);
		return (-1);
	}
	if ((*ret = malloc(sizeof(char) * (n + 1))) == NULL)
		return (-1);
	ft_pri_print(*ret, fmt, opts);
	(*ret)[n] = '\0';
	ft_hlist_apply(opts, (t_f_action) & ft_pri_opts_delete);
	ft_hlist_delete(opts);
	return (n);
}
