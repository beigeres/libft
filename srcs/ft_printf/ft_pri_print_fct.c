/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_print_fct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:30:48 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/18 15:27:50 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pri_print_pref(char *str, t_pri_opts *opts)
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
		ft_pri_sputnwstr(str, opts->elem.v_wstr, opts->little_size);
}
