/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:30:07 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/14 11:54:54 by etrobert         ###   ########.fr       */
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

/*
** Needed for ptrdiff_t
*/

# include <stddef.h>

/*
** Needed for wint_t && wchar_t
*/

# include <wchar.h>

# include "ft_hlist.h"
# include "ft_base.h"
# include "ft_math.h"
# include "ft_bool.h"
# include "ft_char_tools.h"
# include "ft_string.h"
# include "ft_wchar.h"

# define FMT_BOLD 1
# define FMT_DIM 2
# define FMT_UNDERLINED 4
# define FMT_BLINK 5
# define FMT_REVERSE 7
# define FMT_HIDDEN

# define FMT_RESET 0
# define FMT_RESET_BOLD 21
# define FMT_RESET_DIM 22
# define FMT_RESET_UNDERLINED 24
# define FMT_RESET_BLINK 25
# define FMT_RESET_REVERSE 27
# define FMT_RESET_HIDDEN 28

# define FMT_DEFAULT 39
# define FMT_BLACK 30
# define FMT_RED 31
# define FMT_GREEN 32
# define FMT_YELLOW 33
# define FMT_BLUE 34
# define FMT_MAGENTA 35
# define FMT_CYAN 36
# define FMT_LIGHT_GREY 37
# define FMT_DARK_GREY 90
# define FMT_LRED 91
# define FMT_LGREEN 92
# define FMT_FG_LYELLOW 93
# define FMT_LBLUE 94
# define FMT_LMAGENTA 95
# define FMT_LCYAN 96
# define FMT_WHITE 97

typedef unsigned int	t_pri_fmt;

typedef union	u_pri_elem
{
	intmax_t	v_int;
	uintmax_t	v_uint;
	char		v_char;
	wchar_t		v_wchar;
	char		*v_str;
	wchar_t		*v_wstr;
	t_pri_fmt	v_fmt;
}				t_pri_elem;

typedef enum	e_pri_sign
{
	PRI_SDEFAULT,
	PRI_SSIGN_ON,
	PRI_SSPACE
}				t_pri_sign;

typedef enum	e_pri_mode
{
	PRI_MWIDTH,
	PRI_MPREC,
	PRI_MPREC_STARTING,
	PRI_MDEFAULT
}				t_pri_mode;

typedef enum	e_pri_spec
{
	PRI_INT,
	PRI_UINT,
	PRI_OCTAL,
	PRI_HEXA,
	PRI_HEXA_MAJ,
	PRI_BIN,
	PRI_STRING,
	PRI_WSTRING,
	PRI_PERCENT,
	PRI_CHAR,
	PRI_WCHAR,
	PRI_POINTER,
	PRI_FMT
}				t_pri_spec;

typedef enum	e_pri_length
{
	PRI_DEFAULT,
	PRI_HH,
	PRI_H,
	PRI_Z,
	PRI_T,
	PRI_L,
	PRI_LL,
	PRI_J
}				t_pri_length;

typedef struct	s_pri_opts
{
	t_bool			left_justify;
	t_pri_sign		sign;
	t_bool			sharp;
	char			width_char;

	unsigned int	width;

	unsigned int	precision;
	t_bool			prec_set;

	t_pri_length	length;
	t_pri_spec		spec;

	t_base			*base;

	t_pri_elem		elem;

	unsigned int	size;
	unsigned int	little_size;
	unsigned int	next_char;
}				t_pri_opts;

/*
** ft_pri_size_fct.c
*/

unsigned int	ft_pri_octal_prec(const t_pri_opts *opts);
unsigned int	ft_pri_size_pref(const t_pri_opts *opts);
unsigned int	ft_pri_uint_size_digs(uintmax_t n, const t_pri_opts *opts);
unsigned int	ft_pri_size_sign(const t_pri_opts *opts);
unsigned int	ft_pri_uint_size_prec(uintmax_t n, const t_pri_opts *opts);

/*
** ft_pri_print_fct.c
*/

void			ft_pri_print_str(char *str, t_pri_opts *opts);
void			ft_pri_print_pref(char *str, t_pri_opts *opts);
void			ft_pri_print_wstr(char *str, t_pri_opts *opts);

/*
** ft_pri_format_fct.c
*/

t_bool			ft_pri_format_spec(char fmt, t_pri_opts *opts, va_list ap);
t_bool			ft_pri_format_flags(char fmt, t_pri_opts *opts);
t_bool			ft_pri_format_length(char fmt, t_pri_opts *opts);

/*
** ft_pri_format_units.c
*/

t_bool			ft_pri_format_unit(const char *fmt, va_list ap,
		unsigned int *i, t_pri_opts *opts);

/*
** ft_pri_is_number.c
*/

t_bool			ft_pri_is_number(const t_pri_opts *opts);

/*
** ft_pri_valid_format.cc
*/

t_bool			ft_pri_valid_format(t_pri_fmt fmt);

/*
** ft_pri_print_fmt.c
*/

void			ft_pri_print_fmt(char **str, const char *fmt, int i);

unsigned int	ft_pri_size_width(t_pri_opts *opts);
int				ft_pri_size_little_size(const t_pri_opts *opts);

t_pri_opts		*ft_pri_format(const char *fmt, va_list ap, unsigned int *i);

t_pri_opts		*ft_pri_opts_new(void);
void			ft_pri_opts_delete(t_pri_opts *opts);
void			ft_pri_set_opts_default(t_pri_opts *opt);

void			ft_pri_fmt_unsigned(t_pri_opts *opts, va_list ap);

void			ft_pri_fmt_d(t_pri_opts *opts, va_list ap);
void			ft_pri_fmt_d_maj(t_pri_opts *opts, va_list ap);
void			ft_pri_fmt_u(t_pri_opts *opts, va_list ap);
void			ft_pri_fmt_u_maj(t_pri_opts *opts, va_list ap);
void			ft_pri_fmt_b(t_pri_opts *opts, va_list ap);
void			ft_pri_fmt_o(t_pri_opts *opts, va_list ap);
void			ft_pri_fmt_o_maj(t_pri_opts *opts, va_list ap);
void			ft_pri_fmt_x(t_pri_opts *opts, va_list ap);
void			ft_pri_fmt_x_maj(t_pri_opts *opts, va_list ap);
void			ft_pri_fmt_c(t_pri_opts *opts, va_list ap);
void			ft_pri_fmt_c_maj(t_pri_opts *opts, va_list ap);
void			ft_pri_fmt_s(t_pri_opts *opts, va_list ap);
void			ft_pri_fmt_s_maj(t_pri_opts *opts, va_list ap);
void			ft_pri_fmt_p(t_pri_opts *opts, va_list ap);
void			ft_pri_fmt_percent(t_pri_opts *opts);
void			ft_pri_fmt_fmt(t_pri_opts *opts, va_list ap);

int				ft_pri_decrypt_format(const char *fmt, va_list ap,
		t_hlist *opts);
void			ft_pri_print(char *str, const char *fmt, t_hlist *opts);

int				ft_printf(const char *fmt, ...);
int				ft_sprintf(char *str, const char *fmt, ...);
int				ft_asprintf(char **ret, const char *fmt, ...);
int				ft_dprintf(int fd, const char *fmt, ...);

int				ft_vprintf(const char *fmt, va_list ap);
int				ft_vsprintf(char *str, const char *fmt, va_list ap);
int				ft_vasprintf(char **ret, const char *fmt, va_list ap);
int				ft_vdprintf(int fd, const char *fmt, va_list ap);

#endif
