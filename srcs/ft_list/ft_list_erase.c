/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_erase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:22:38 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/26 20:50:10 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list_it	ft_list_erase(t_list *list, t_list_it it)
{
	t_list_it	ret;

	if (list == NULL)
		return (NULL);
	if (it == NULL)
		return (NULL);
	if (it->prev != NULL)
		it->prev->next = it->next;
	else
		list->first = it->next;
	if (it->next != NULL)
		it->next->prev = it->prev;
	else
		list->last = it->prev;
	ret = it->next;
	ft_list_e_delete(it);
	list->m_size--;
	return (ret);
}
