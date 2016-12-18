/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hlist_it.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 15:39:33 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/27 18:47:14 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hlist.h"

t_hlist_it		ft_hlist_it_first(t_hlist *list)
{
	return (ft_slist_it_first(list->first));
}

t_hlist_it		ft_hlist_it_next(t_hlist_it it)
{
	return (ft_slist_it_next(it));
}

void			*ft_hlist_it_get(t_hlist_it it)
{
	return (ft_slist_it_get(it));
}

t_bool			ft_hlist_it_end(t_hlist_it it)
{
	return (ft_slist_it_end(it));
}
