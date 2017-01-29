/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_push_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:55:54 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/27 19:56:08 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_slist.h"

bool		ft_slist_push_front(t_slist **slist, void *content)
{
	t_slist	*elem;

	if (slist == NULL)
		return (false);
	if ((elem = ft_slist_new(content)) == NULL)
		return (false);
	elem->next = *slist;
	*slist = elem;
	return (true);
}
