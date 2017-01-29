/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 18:23:17 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/29 18:23:55 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SET_H
# define FT_SET_H

# include <stdlib.h>
# include <stdbool.h>

# include "ft_defines.h"

typedef struct s_set_e	t_set_e;

struct			s_set_e
{
	void		*val;
	t_set_e		*right;
	t_set_e		*left;
	t_set_e		*parent;
};

typedef struct	s_set
{
	size_t		size;
	t_set_e		*root;
	t_f_compare	less;
}				t_set;

typedef t_set_e	*t_set_it;

/*
** Basics
*/

t_set			*ft_set_new(t_f_compare f);
void			ft_set_delete(t_set *set);

/*
** Iterators
** Dont use ft_set_end as it doesnt work for an int marker in an array
*/

t_set_it		ft_set_begin(const t_set *set);
t_set_it		ft_set_end(const t_set *set);

bool			ft_set_it_end(const t_set *set, t_set_it it);
void			*ft_set_it_get(const t_set *set, t_set_it it);

void			ft_set_it_inc(t_set_it *it);
void			ft_set_it_dec(t_set_it *it);
t_set_it		ft_set_it_next(t_set_it it);
t_set_it		*ft_set_it_next_n(t_set_it it, t_distance n);
void			ft_set_it_advance(t_set_it *it, t_distance n);

/*
** Modifiers
*/

int				ft_set_insert(t_set *set, void *val);

/*
** Internal
*/

t_set_e			*ft_set_e_new(void *val, t_set_e *right, t_set_e *left,
		t_set_e *parent);
void			ft_set_e_delete(t_set_e *elem);

t_set_e			*ft_set_e_grandparent(t_set_e *elem);
t_set_e			*ft_set_e_uncle(t_set_e *elem);

int				ft_set_insert_r(t_set_e *elem, t_f_compare less, void *val);
void			ft_set_rotate_left(t_set *set, t_set_e *elem);

#endif
