/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 18:23:17 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/20 19:30:24 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SET_H
# define FT_SET_H

# include <stdlib.h>
# include <stdbool.h>

typedef bool	(*t_f_compare)(void *, void *);

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

/*
** Basics
*/

t_set			*ft_set_new(t_f_compare f);
void			ft_set_delete(t_set *set);

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
int				ft_set_insert_r(t_set_e *elem, t_f_compare less, void *val);

#endif
