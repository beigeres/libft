/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_it.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:59:41 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/09 11:29:48 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_slist.h"

t_slist_it		ft_slist_it_first(t_slist *list)
{
	return (list);
}

t_slist_it		ft_slist_it_next(t_slist_it it)
{
	if (it == NULL)
		return (NULL);
	return (it->next);
}

void			*ft_slist_it_get(t_slist_it it)
{
	if (it == NULL)
		return (NULL);
	return (it->content);
}

bool			ft_slist_it_end(t_slist_it it)
{
	return (it == NULL);
}
