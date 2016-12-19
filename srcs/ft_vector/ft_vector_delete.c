/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 17:18:31 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/19 17:19:32 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void		ft_vector_delete(t_vector *vec)
{
	if (vec == NULL)
		return ;
	if (vec->tab != NULL)
		free(vec->tab);
	free(vec);
}
