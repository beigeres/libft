/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:30:07 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/24 19:07:56 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_base.h"
# include "ft_math.h"
# include "ft_bool.h"

// ne pourrait on pas cast dans un truc gros systematiquement ?
typedef union	u_pri_elem
{
	long long int			v_ll; // used for UNSIGNED OCTAL HEXA HEXA_MAJ
	unsigned long long int	v_ull;
}				t_pri_elem;

typedef enum	e_pri_sign
{
	DEFAULT,
	SIGN_ON,
	SPACE
}				t_pri_sign;

typedef enum	e_pri_spec
{
	PRI_INT,
	PRI_UNSIGNED,
	PRI_OCTAL,
	PRI_HEXA,
	PRI_HEXA_MAJ,
	PRI_STRING
}				t_pri_spec;

typedef struct	s_pri_opts
{
	t_bool			left_justify;
	t_pri_sign		sign;
	t_bool			sharp;
	t_bool			zero;

	unsigned int	width;

	unsigned int	precision;

	t_pri_spec		spec;

	t_base			*base;

	t_pri_elem		elem;
}				t_pri_opts;

// a virer
unsigned int	ft_pri_ull_size_prec(unsigned long long int n,
		const t_pri_opts *opts);
unsigned int	ft_pri_size_pref(const t_pri_opts *opts);

unsigned int	ft_pri_size_width(const t_pri_opts *opts);

void			ft_pri_set_opts_default(t_pri_opts *opt);

#endif
