/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_is_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 20:08:03 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/09 11:35:41 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool		ft_pri_is_number(const t_pri_opts *opts)
{
	return (opts->spec == PRI_INT || opts->spec == PRI_UINT ||
			opts->spec == PRI_OCTAL || opts->spec == PRI_HEXA ||
			opts->spec == PRI_HEXA || opts->spec == PRI_HEXA_MAJ ||
			opts->spec == PRI_BIN || opts->spec == PRI_POINTER);
}
