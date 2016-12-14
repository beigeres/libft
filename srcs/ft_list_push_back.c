/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:05:32 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/14 17:27:18 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void			ft_list_push_back(t_list *list, void *val)
{
	t_list_e	*elem;

	if (list == NULL)
		return ;
	if ((elem = ft_list_e_new(val, list->last, NULL)) == NULL)
		return ;
	if (ft_list_empty(list))
		list->first = elem;
	else
		list->last->next = elem;
	list->last = elem;
	++list->size;
}
