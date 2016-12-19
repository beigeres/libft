/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_init_min_capacity.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:54:06 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/19 21:07:22 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

static size_t	ft_vector_init_get_capacity(size_t min_capacity)
{
	size_t	capacity;

	if (min_capacity == 0)
		return (0);
	capacity = 1;
	while (capacity < min_capacity)
		capacity *= 2;
	return (capacity);
}

void			ft_vector_init_min_capacity(t_vector *vec,
		size_t elem_size, size_t min_capacity)
{
	size_t	capacity;

	if (vec == NULL)
		return ;
	capacity = ft_vector_init_get_capacity(min_capacity);
	if ((vec->tab = malloc(capacity * elem_size)) == NULL)
		return ;
	vec->capacity = capacity;
	vec->size = 0;
	vec->elem_size = elem_size;
}
