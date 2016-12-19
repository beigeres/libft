/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_init_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 17:36:04 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/19 18:58:51 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void		ft_vector_init_size(t_vector *vec, size_t elem_size, size_t size)
{
	ft_vector_init_min_capacity(vec, elem_size, size);
}
