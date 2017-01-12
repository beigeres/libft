/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 10:47:36 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/12 10:59:36 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list_it		ft_list_find(const t_list *list, void *ref)
{
	t_list_it	it;

	it = ft_list_begin(list);
	while (!ft_list_it_end(list, it))
	{
		if (ref == ft_list_it_get(list, it))
			return (it);
		ft_list_it_inc(&it);
	}
	return (ft_list_end(list));
}
