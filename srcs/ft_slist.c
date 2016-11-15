/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:46:36 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/15 15:59:21 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_slist.h"

void	ft_slist_push_front(t_slist **slist, void *content)
{
	t_slist	*elem;

	if (slist == NULL)
		return ;
	if ((elem = malloc(sizeof(t_slist))) == NULL)
		return ;
	elem->content = content;
	elem->next = *slist;
	*slist = elem;
}

void	*ft_slist_find(t_slist *slist, void *ref, t_f_comp f)
{
	while (slist != NULL)
	{
		if ((*f)(slist->content, ref))
			return (slist->content);
		slist = slist->next;
	}
	return (NULL);
}

void	ft_slist_remove(t_slist **slist, void *content)
{
	t_slist	*elem;
	t_slist	*tmp;

	if (slist == NULL)
		return ;
	if (*slist == NULL)
		return ;
	if ((*slist)->content == content)
	{
		tmp = (*slist)->next;
		free(*slist);
		*slist = tmp;
		return ;
	}
	elem = *slist;
	while (elem->next != NULL)
	{
		if (elem->next->content == content)
		{
			tmp = elem->next->next;
			free(elem->next);
			elem->next = tmp;
			return ;
		}
		elem = elem->next;
	}
}

void		ft_slist_apply(t_slist *slist, void (*f)(void *))
{
	while (slist != NULL)
	{
		(*f)(slist->content);
		slist = slist->next;
	}
}

int			ft_slist_count_if(t_slist *slist, t_bool (*f)(void *))
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
