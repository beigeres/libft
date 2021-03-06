/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 18:17:46 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/09 11:31:21 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hlist.h"

t_hlist	*ft_hlist_new(void)
{
	t_hlist	*list;

	if ((list = (t_hlist *)malloc(sizeof(*list))) == NULL)
		return (NULL);
	list->first = NULL;
	list->last = NULL;
	return (list);
}

void	ft_hlist_delete(t_hlist *list)
{
	if (list == NULL)
		return ;
	while (list->first != NULL)
		ft_slist_pop_front(&(list->first));
	free(list);
}

bool	ft_hlist_push_back(t_hlist *list, void *data)
{
	t_slist	*elem;

	if ((elem = ft_slist_new(data)) == NULL)
		return (false);
	if (list->last == NULL)
		list->first = elem;
	else
		list->last->next = elem;
	list->last = elem;
	return (true);
}

bool	ft_hlist_push_front(t_hlist *list, void *data)
{
	if (!ft_slist_push_front(&(list->first), data))
		return (false);
	if (list->last == NULL)
		list->last = list->first;
	return (true);
}

void	*ft_hlist_back(t_hlist *list)
{
	if (list == NULL)
		return (NULL);
	if (list->last == NULL)
		return (NULL);
	return (list->last->content);
}
