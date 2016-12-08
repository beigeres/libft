/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_opts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:36:51 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/07 15:46:31 by etrobert         ###   ########.fr       */
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
	if (opts->base != NULL)
		ft_base_delete(opts->base);
	free(opts);
}

void			ft_pri_set_opts_default(t_pri_opts *opt)
{
	opt->left_justify = FALSE;
	opt->sign = PRI_SDEFAULT;
	opt->sharp = FALSE;
	opt->width_char = ' ';
	opt->width = 0;
	opt->precision = 1;
	opt->prec_set = FALSE;
	opt->length = PRI_DEFAULT;
	opt->spec = PRI_INT;
	opt->base = NULL;
	opt->size = 0;
	opt->little_size = 0;
	opt->next_char = 0;
}
