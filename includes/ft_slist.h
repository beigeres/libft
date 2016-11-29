/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:43:00 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/28 17:55:27 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Simple List
*/

#ifndef FT_SLIST_H
# define FT_SLIST_H

# include <stdlib.h>
# include "ft_bool.h"

typedef t_bool	(*t_f_comp)(void *, void *);
typedef void	(*t_f_action)(void *);

typedef struct	s_slist
{
	void			*content;
	struct s_slist	*next;
}				t_slist;

typedef t_slist	*t_slist_it;

t_slist			*ft_slist_new(void *content);

t_bool			ft_slist_push_front(t_slist **ptr, void *content);
void			ft_slist_pop_front(t_slist **slist);

void			*ft_slist_find(t_slist *slist, void *ref, t_f_comp f);
void			ft_slist_remove(t_slist **slist, void *content);

void			ft_slist_apply(t_slist *slist, void (*f)(void *));
int				ft_slist_count_if(t_slist *slist, t_bool (*f)(void *));

t_slist_it		ft_slist_it_first(t_slist *list);
t_slist_it		ft_slist_it_next(t_slist_it it);
void			*ft_slist_it_get(t_slist_it it);
t_bool			ft_slist_it_end(t_slist_it it);

#endif
