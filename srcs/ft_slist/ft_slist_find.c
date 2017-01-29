/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:59:03 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/27 19:59:19 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_slist.h"

void		*ft_slist_find(t_slist *slist, void *ref, t_f_comp f)
{
	while (slist != NULL)
	{
		if ((*f)(slist->content, ref))
			return (slist->content);
		slist = slist->next;
	}
	return (NULL);
}
