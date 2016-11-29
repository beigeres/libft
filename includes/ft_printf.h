/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:30:07 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/29 18:07:04 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** Needed for intmax_t and uintmax_t
*/

# include <stdint.h>

/*
** Needed for va_list and stuff
*/

# include <stdarg.h>

/*
** Needed for write
*/

# include <unistd.h>

/*
** Needed for free
*/

# include <stdlib.h>

# include "ft_hlist.h"
# include "ft_base.h"
# include "ft_math.h"
# include "ft_bool.h"
# include "ft_char_tools.h"

typedef union	u_pri_elem
{
	intmax_t	v_int; 
	uintmax_t	v_uint; // used for UINT OCTAL HEXA HEXA_MAJ
}				t_pri_elem;

typedef enum	e_pri_sign
{
	PRI_DEFAULT,
	PRI_SIGN_ON,
	PRI_SPACE
}				t_pri_sign;

typedef enum	e_pri_mode
{
	PRI_MWIDTH,
	PRI_MPREC,
	PRI_MDEFAULT
}				t_pri_mode;

typedef enum	e_pri_spec
{
	PRI_INT,
	PRI_UINT,
	PRI_OCTAL,
	PRI_HEXA,
	PRI_HEXA_MAJ,
	PRI_STRING,
	PRI_PERCENT
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

	unsigned int	size;
}				t_pri_opts;

unsigned int	ft_pri_size_width(const t_pri_opts *opts);

t_pri_opts		*ft_pri_opts_new(void);
void			ft_pri_set_opts_default(t_pri_opts *opt);

int			ft_pri_decrypt_format(const char *fmt, va_list ap, t_hlist *opts);

int		ft_printf(const char *fmt, ...);
int		ft_sprintf(char *str, const char *fmt, ...);
int		ft_asprintf(char **ret, const char *fmt, ...);
int		ft_dprintf(int fd, const char *fmt, ...);

int		ft_vprintf(const char *fmt, va_list ap);
int		ft_vsprintf(char *str, const char *fmt, va_list ap);
int		ft_vasprintf(char **ret, const char *fmt, va_list ap);
int		ft_vdprintf(int fd, const char *fmt, va_list ap);

#endif
