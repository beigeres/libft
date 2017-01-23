/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_it_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:20:54 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/23 17:32:43 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_set.h"

t_set_it		ft_set_it_next(t_set_it it)
{
	t_set_e		*tmp;

	if (it == NULL)
		return (NULL);
	if (it->right != NULL)
	{
		it = it->right;
		while (it->left != NULL)
			it = it->left;
		return (it);
	}
	tmp = it;
	it = it->parent;
	while (it != NULL && tmp != it->left)
	{
		tmp = it;
		it = it->parent;
	}
	return (it);
}
