/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_decrypt_format.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 20:09:36 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/12 20:09:42 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
