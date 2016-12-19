/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_new_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 17:32:34 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/19 18:58:17 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	*ft_vector_new_size(size_t elem_size, size_t size)
{
	t_vector	*vec;

	if ((vec = malloc(sizeof(*vec))) == NULL)
		return (NULL);
	ft_vector_init_size(vec, elem_size, size);
	return (vec);
}
