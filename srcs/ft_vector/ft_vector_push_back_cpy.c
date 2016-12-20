/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_push_back_cpy.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 20:33:36 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/20 20:35:06 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void			ft_vector_push_back_cpy(t_vector *vec, void *ref)
{
	ft_vector_push_back(vec);
	ft_memcpy(ft_vector_back(vec), ref, vec->elem_size);
}
