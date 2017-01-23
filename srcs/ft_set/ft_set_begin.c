/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_begin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:08:13 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/23 17:10:55 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_set.h"

t_set_it		ft_set_begin(const t_set *set)
{
	t_set_e		*elem;

	if (set == NULL)
		return (NULL);
	elem = set->root;
	if (elem == NULL)
		return (NULL);
	while (elem->left != NULL)
		elem = elem->left;
	return (elem);
}
