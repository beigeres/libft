/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:21:35 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/18 16:15:14 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void			ft_list_insert(t_list *list, t_list_it it, void *val)
{
	t_list_e	*elem;

	if (list == NULL)
		return ;
	if (it == NULL)
	{
		ft_list_push_back(list, val);
		return ;
	}
	if ((elem = ft_list_e_new(val, it->prev, it)) == NULL)
		return ;
	it->prev = elem;
	if (elem->prev != NULL)
		elem->prev->next = elem;
	++list->size;
}
