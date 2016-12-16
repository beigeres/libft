/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_size_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:02:23 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/14 11:10:17 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_pri_size_width(t_pri_opts *opts)
{
	if (opts->width_char == '0' && !opts->left_justify &&
			opts->width > opts->little_size && ft_pri_is_number(opts))
	{
		opts->precision += opts->width - opts->little_size;
		opts->little_size += opts->width - opts->little_size;
	}
	if (opts->spec == PRI_FMT)
		return (opts->little_size);
	return (ft_umax(opts->little_size, opts->width));
}
