/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 17:12:20 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/19 18:57:12 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	*ft_vector_new(size_t elem_size)
{
	t_vector	*vec;

	if ((vec = malloc(sizeof(*vec))) == NULL)
		return (NULL);
	ft_vector_init(vec, elem_size);
	return (vec);
}
