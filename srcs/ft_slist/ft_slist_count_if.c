/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_count_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 20:00:04 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/27 20:00:06 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_slist.h"

int			ft_slist_count_if(t_slist *slist, bool (*f)(void *))
{
	int			n;

	n = 0;
	while (slist != NULL)
	{
		if ((*f)(slist->content))
			n++;
		slist = slist->next;
	}
	return (n);
}
