/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hlist_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:59:45 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/09 11:32:06 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hlist.h"

void			ft_hlist_apply(t_hlist *list, t_f_action f)
{
	ft_slist_apply(list->first, f);
}

int				ft_hlist_count_if(t_hlist *list, bool (*f)(void *))
{
	return (ft_slist_count_if(list->first, f));
}
