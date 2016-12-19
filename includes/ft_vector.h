/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 20:54:14 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/19 21:06:02 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <stdlib.h>
# include <stdbool.h>

# include "ft_memory.h"

typedef struct	s_vector
{
	void		*tab;
	size_t		size;
	size_t		capacity;
	size_t		elem_size;
}				t_vector;

/*
** Basics
*/

t_vector		*ft_vector_new(size_t elem_size);
t_vector		*ft_vector_new_size(size_t elem_size, size_t size);

void			ft_vector_init(t_vector *vec, size_t elem_size);
void			ft_vector_init_size(t_vector *vec,
		size_t elem_size, size_t size);
void			ft_vector_init_min_capacity(t_vector *vec,
		size_t elem_size, size_t min_capacity);

void			ft_vector_delete(t_vector *vec);

/*
** Element access
*/

void			*ft_vector_at(t_vector *vec, size_t i);
void			*ft_vector_back(t_vector *vec);
void			*ft_vector_front(t_vector *vec);

/*
** Capacity
*/

size_t			ft_vector_capacity(t_vector *vec);
bool			ft_vector_empty(t_vector *vec);
void			ft_vector_reserve(t_vector *vec, size_t size);

/*
** Modifiers
*/

void			ft_vector_push_back(t_vector *vec);
void			ft_vector_pop_back(t_vector *vec);
void			ft_vector_swap(t_vector *vec1, t_vector *vec2);
void			ft_vector_clear(t_vector *vec);

#endif
