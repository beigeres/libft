/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_push_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 17:49:33 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/19 19:52:15 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void		ft_vector_push_back(t_vector *vec)
{
	if (vec == NULL)
		return ;
	ft_vector_reserve(vec, vec->size + 1);
	++vec->size;
}
