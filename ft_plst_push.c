/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plst_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:33:37 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/10 18:34:28 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_plst.h"

static	t_plst_e	*ft_plst_e_new(void *content,
		t_plst_e *next)
{
	t_plst_e	*elem;

	if ((elem = (t_plst_e *)malloc(sizeof(t_plst_e))) == NULL)
		return (NULL);
	elem->content = content;
	elem->next = next;
	return (elem);
}

t_plst				*ft_plst_push_front(t_plst *plst, void *content)
{
	if (plst->size == 0)
	{
		if ((plst->first = ft_plst_e_new(content, NULL)) == NULL)
			return (NULL);
		plst->last = plst->first;
	}
	else
	{
		if ((plst->first = ft_plst_e_new(content, plst->first)) == NULL)
			return (NULL);
	}
	plst->size++;
	return (plst);
}

t_plst				*ft_plst_push_back(t_plst *plst, void *content)
{
	if (plst->size == 0)
	{
		if ((plst->last = ft_plst_e_new(content, NULL)) == NULL)
			return (NULL);
		plst->first = plst->last;
	}
	else
	{
		if ((plst->last->next =
					ft_plst_e_new(content, NULL)) == NULL)
			return (NULL);
		plst->last = plst->last->next;
	}
	plst->size++;
	return (plst);
}
