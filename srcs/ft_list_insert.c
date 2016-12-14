/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:21:35 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/14 19:27:23 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void			ft_list_insert(t_list_it it, const void *val)
{
	t_list_e	*elem;
	
	// if it is the end it should still put a thing
	// for example if the list is empty
	if (it == NULL)
		return ;
	if ((elem = t_list_e_new(val, it->previous, it)) == NULL)
		return (NULL);
	it->previous = val;
	if (elem->previous != NULL)
		elem->previous->next = elem;
}
