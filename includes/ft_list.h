/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 16:16:21 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/18 16:16:41 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>
# include "ft_bool.h"

typedef unsigned int	t_size_type;
typedef unsigned int	t_distance;

typedef void	(*t_f_apply)(void *);

typedef struct	s_list_e
{
	void			*val;
	struct s_list_e	*prev;
	struct s_list_e	*next;
}				t_list_e;

typedef struct	s_list
{
	t_size_type	size;
	t_list_e	*first;
	t_list_e	*last;
}				t_list;

typedef t_list_e		*t_list_it;

/*
** Basics
*/

t_list			*ft_list_new(void);
void			ft_list_delete(t_list *list);

/*
** Iterators
*/

t_list_it		ft_list_begin(t_list *list);
t_list_it		ft_list_end(t_list *list);

t_bool			ft_list_it_end(t_list *list, t_list_it it);

void			*ft_list_it_get(t_list_it it);
void			ft_list_it_inc(t_list_it *it);
void			ft_list_it_dec(t_list_it *it);
t_list_it		ft_list_it_next(t_list_it it);
t_list_it		ft_list_it_next_n(t_list_it it, t_distance n);
void			ft_list_it_advance(t_list_it *it, t_distance n);

/*
** Capacity
*/

t_bool			ft_list_empty(const t_list *list);
t_size_type		ft_list_size(const t_list *list);

/*
** Element access
*/

void			*ft_list_front(const t_list *list);
void			*ft_list_back(const t_list *list);

/*
** Modifiers
*/

void			ft_list_assign(t_list *list, t_size_type n, const void *val);

void			ft_list_push_back(t_list *list, void *val);
void			ft_list_push_front(t_list *list, void *val);
void			ft_list_insert(t_list *list, t_list_it it, void *val);

void			ft_list_pop_back(t_list *list);
void			ft_list_pop_front(t_list *list);
t_list_it		ft_list_erase(t_list *list, t_list_it it);
void			ft_list_erase_range(t_list *list,
		t_list_it first, t_list_it last);
void			ft_list_clear(t_list *list);

/*
** Extra
*/

void			ft_list_apply(t_list *list, t_f_apply f);

/*
** Internal
*/

t_list_e		*ft_list_e_new(void *val, t_list_e *prev, t_list_e *next);
void			ft_list_e_delete(t_list_e *elem);

#endif
