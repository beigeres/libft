/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 17:20:02 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/20 20:23:16 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	*ft_vector_at(const t_vector *vec, size_t i)
{
	if (vec == NULL)
		return (NULL);
	if (i >= vec->size)
		return (NULL);
	return (vec->tab + (i * vec->elem_size));
}
