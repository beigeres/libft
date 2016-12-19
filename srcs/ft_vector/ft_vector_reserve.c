/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_reserve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 19:38:47 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/19 19:51:32 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void		ft_vector_reserve(t_vector *vec, size_t size)
{
	size_t	new_capacity;

	if (vec == NULL)
		return ;
	if (size <= vec->capacity)
		return ;
	if (vec->capacity == 0)
		new_capacity = 1;
	new_capacity = vec->capacity;
	while (new_capacity < size)
		new_capacity *= 2;
	if ((vec->tab = ft_nrealloc(vec->tab, vec->capacity * vec->elem_size,
					new_capacity * vec->elem_size)) == NULL)
		return ;
	vec->capacity = new_capacity;
}
