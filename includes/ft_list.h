/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 16:16:21 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/17 18:31:11 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>
# include <stdbool.h>

# include "ft_defines.h"

typedef struct s_list_e	t_list_e;
typedef struct s_list	t_list;
typedef t_list_e		*t_list_it;

struct			s_list_e
{
	void		*val;
	t_list_e	*prev;
	t_list_e	*next;
};

struct			s_list
{
	t_size_type	m_size;
	t_list_e	*first;
	t_list_e	*last;
};

/*
** Basics
*/

t_list			*ft_list_new(void);
t_list			*ft_list_cpy(const t_list *list);
void			ft_list_delete(t_list *list);

/*
** Iterators
** Dont use ft_set_end as it doesnt work for an int marker in an array
*/

t_list_it		ft_list_begin(const t_list *list);
t_list_it		ft_list_end(const t_list *list);

bool			ft_list_it_end(const t_list *list, t_list_it it);
void			*ft_list_it_get(const t_list *list, t_list_it it);

void			ft_list_it_inc(t_list_it *it);
void			ft_list_it_dec(t_list_it *it);
t_list_it		ft_list_it_next(t_list_it it);
t_list_it		ft_list_it_next_n(t_list_it it, t_distance n);
void			ft_list_it_advance(t_list_it *it, t_distance n);

/*
** Capacity
*/

bool			ft_list_empty(const t_list *list);
t_size_type		ft_list_size(const t_list *list);

/*
** Element access
*/

void			*ft_list_front(const t_list *list);
void			*ft_list_back(const t_list *list);

/*
** Modifiers
*/

int				ft_list_push_back(t_list *list, void *val);
int				ft_list_push_front(t_list *list, void *val);
int				ft_list_insert(t_list *list, t_list_it it, void *val);

void			ft_list_pop_back(t_list *list);
void			ft_list_pop_front(t_list *list);
t_list_it		ft_list_erase(t_list *list, t_list_it it);
void			ft_list_erase_range(t_list *list,
		t_list_it first, t_list_it last);
void			ft_list_clear(t_list *list);

/*
** Extra
*/

void			ft_list_apply(const t_list *list, t_f_apply f);
int				ft_list_sapply(const t_list *list, t_f_sapply f);
t_list_it		ft_list_find(const t_list *list, void *ref);

/*
** Not Implemented yet
*/

void			ft_list_assign(t_list *list, t_size_type n, const void *val);

/*
** Internal
*/

void			ft_list_init(t_list *list);
t_list_e		*ft_list_e_new(void *val, t_list_e *prev, t_list_e *next);
void			ft_list_e_delete(t_list_e *elem);

#endif
