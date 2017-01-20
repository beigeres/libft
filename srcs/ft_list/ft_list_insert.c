/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:21:35 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/20 19:02:00 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int				ft_list_insert(t_list *list, t_list_it it, void *val)
{
	t_list_e	*elem;

	if (list == NULL)
		return (0);
	if (it == NULL)
	{
		ft_list_push_back(list, val);
		return (0);
	}
	if ((elem = ft_list_e_new(val, it->prev, it)) == NULL)
		return (-1);
	it->prev = elem;
	if (elem->prev != NULL)
		elem->prev->next = elem;
	++list->size;
	return (0);
}
