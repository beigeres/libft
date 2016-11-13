/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:21:43 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/13 20:23:15 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PLST_H
# define FT_PLST_H

# include "ft_bool.h"

# include <stdlib.h>

typedef struct	s_plst_e
{
	void			*content;
	struct s_plst_e	*next;
}				t_plst_e;

typedef struct	s_plst
{
	t_plst_e	*first;
	t_plst_e	*last;
	int			size;
}				t_plst;

/*
** ft_plst.c
*/

t_plst			*ft_plst_new(void);
void			ft_plst_delete(t_plst *plst);

void			ft_plst_pop_front(t_plst *plst);

/*
** ft_plst_push_back.c
*/

t_plst			*ft_plst_push_back(t_plst *plst, void *content);
t_plst			*ft_plst_push_front(t_plst *plst, void *content);

/*
** ft_plst_utils.c
*/

void			ft_plst_apply(t_plst *plst, void (*f)(void *));
int				ft_plst_count_if(t_plst *plst, t_bool (*f)(void *));
void			*ft_plst_find(t_plst *plst, t_bool (*f)(void *));

#endif
