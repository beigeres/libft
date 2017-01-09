/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_opts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:36:51 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/09 11:34:15 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pri_opts		*ft_pri_opts_new(void)
{
	t_pri_opts	*opts;

	if ((opts = malloc(sizeof(*opts))) == NULL)
		return (NULL);
	ft_pri_set_opts_default(opts);
	return (opts);
}

void			ft_pri_opts_delete(t_pri_opts *opts)
{
	if (opts == NULL)
		return ;
	if (opts->base != NULL)
		ft_base_delete(opts->base);
	free(opts);
}

void			ft_pri_set_opts_default(t_pri_opts *opt)
{
	opt->left_justify = false;
	opt->sign = PRI_SDEFAULT;
	opt->sharp = false;
	opt->width_char = ' ';
	opt->width = 0;
	opt->precision = 1;
	opt->prec_set = false;
	opt->length = PRI_DEFAULT;
	opt->spec = PRI_INT;
	opt->base = NULL;
	opt->size = 0;
	opt->little_size = 0;
	opt->next_char = 0;
}
