/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_cpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:11:06 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/09 15:44:18 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list			*ft_list_cpy(t_list *list)
{
	t_list		*cpy;
	t_list_it	it;

	if ((cpy = ft_list_new()) == NULL)
		return (NULL);
	it = ft_list_begin(list);
	while (!ft_list_it_end(list, it))
	{
		if (ft_list_push_back(cpy, ft_list_it_get(it)) == -1)
		{
			ft_list_delete(cpy);
			return (NULL);
		}
		ft_list_it_inc(&it);
	}
	return (cpy);
}
