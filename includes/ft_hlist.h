/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hlist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:45:25 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/28 17:58:57 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HLIST_H
# define FT_HLIST_H

# include "ft_slist.h"

typedef t_slist_it	t_hlist_it;

typedef struct	s_hlist
{
	t_slist	*first;
	t_slist	*last;
}				t_hlist;

t_hlist			*ft_hlist_new(void);
void			ft_hlist_delete(t_hlist *list);

t_bool			ft_hlist_push_back(t_hlist *list, void *data);
t_bool			ft_hlist_push_front(t_hlist *list, void *data);

void			*ft_hlist_back(t_hlist *list);

void			ft_hlist_pop_front(t_hlist *list);
void			ft_hlist_pop_back(t_hlist *list);

void			ft_hlist_find(t_hlist *list, void *ref, t_f_comp f);
void			ft_hlist_remove(t_hlist *list, void *content);

void			ft_hlist_apply(t_hlist *list, t_f_action f);
int				ft_hlist_count_if(t_hlist *list, t_bool (*f)(void *));

t_hlist_it		ft_hlist_it_first(t_hlist *list);
t_hlist_it		ft_hlist_it_next(t_hlist_it it);
void			*ft_hlist_it_get(t_hlist_it it);
t_bool			ft_hlist_it_end(t_hlist_it it);

#endif
