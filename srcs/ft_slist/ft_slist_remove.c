/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:56:47 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/27 19:56:56 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_slist.h"

void		ft_slist_remove(t_slist **slist, void *content)
{
	t_slist	*elem;

	if (slist == NULL)
		return ;
	if (*slist == NULL)
		return ;
	if ((*slist)->content == content)
	{
		ft_slist_pop_front(slist);
		return ;
	}
	elem = *slist;
	while (elem->next != NULL)
	{
		if (elem->next->content == content)
		{
			ft_slist_pop_front(&(elem->next));
			return ;
		}
		elem = elem->next;
	}
}
