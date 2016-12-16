/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:29:26 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/14 17:27:37 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void			ft_list_push_front(t_list *list, void *val)
{
	t_list_e	*elem;

	if (list == NULL)
		return ;
	if ((elem = ft_list_e_new(val, NULL, list->first)) == NULL)
		return ;
	if (ft_list_empty(list))
		list->last = elem;
	else
		list->first->prev = elem;
	list->first = elem;
	++list->size;
}
