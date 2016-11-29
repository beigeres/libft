/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:46:36 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/28 17:54:27 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_slist.h"

t_slist		*ft_slist_new(void *content)
{
	t_slist	*list;

	if ((list = (t_slist *)malloc(sizeof(*list))) == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

t_bool		ft_slist_push_front(t_slist **slist, void *content)
{
	t_slist	*elem;

	if (slist == NULL)
		return (FALSE);
	if ((elem = ft_slist_new(content)) == NULL)
		return (FALSE);
	elem->next = *slist;
	*slist = elem;
	return (TRUE);
}

void		ft_slist_pop_front(t_slist **slist)
{
	t_slist	*tmp;

	if (slist == NULL)
		return ;
	if (*slist == NULL)
		return ;
	tmp = (*slist)->next;
	free(*slist);
	*slist = tmp;
}

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
