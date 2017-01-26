/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 20:33:07 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/26 21:07:53 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static void	ft_list_init_functions(t_list *list)
{
	list->cpy = ft_list_cpy;
	list->free = ft_list_delete;
	list->begin = ft_list_begin;
	list->end = ft_list_end;
	list->it_end = ft_list_it_end;
	list->it_get = ft_list_it_get;
	list->empty = ft_list_empty;
	list->size = ft_list_size;
	list->front = ft_list_front;
	list->back = ft_list_back;
	list->push_back = ft_list_push_back;
	list->push_front = ft_list_push_front;
	list->insert = ft_list_insert;
	list->pop_back = ft_list_pop_back;
	list->pop_front = ft_list_pop_front;
	list->erase = ft_list_erase;
	list->erase_range = ft_list_erase_range;
	list->clear = ft_list_clear;
	list->apply = ft_list_apply;
	list->find = ft_list_find;
}

void		ft_list_init(t_list *list)
{
	ft_list_init_functions(list);
	list->m_size = 0;
	list->first = NULL;
	list->last = NULL;
}
