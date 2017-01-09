/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:50:13 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/09 11:30:14 by etrobert         ###   ########.fr       */
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

void		ft_slist_apply(t_slist *slist, void (*f)(void *))
{
	if (f == NULL)
		return ;
	while (slist != NULL)
	{
		(*f)(slist->content);
		slist = slist->next;
	}
}

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
