/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plst_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:11:21 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/14 19:00:22 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_plst.h"

void		ft_plst_apply(t_plst *plst, void (*f)(void *))
{
	t_plst_e	*elem;

	if (plst == NULL)
		return ;
	elem = plst->first;
	while (elem != NULL)
	{
		(*f)(elem->content);
		elem = elem->next;
	}
}

int			ft_plst_count_if(t_plst *plst, t_bool (*f)(void *))
{
	t_plst_e	*elem;
	int			n;

	if (plst == NULL)
		return (-1);
	n = 0;
	elem = plst->first;
	while (elem != NULL)
	{
		if ((*f)(elem->content))
			n++;
		elem = elem->next;
	}
	return (n);
}

void		*ft_plst_find(t_plst *plst, void *ref, t_bool (*f)(void *, void *))
{
	t_plst_e	*elem;

	if (plst == NULL)
		return (NULL);
	elem = plst->first;
	while (elem != NULL)
	{
		if ((*f)(elem->content, ref))
			return (elem->content);
		elem = elem->next;
	}
	return (NULL);
}

static void	ft_plst_remove_next(t_plst_e **ptr)
{
	t_plst_e	*tmp;

	tmp = (*ptr)->next;
	free(*ptr);
	*ptr = tmp;
}

void		ft_plst_remove(t_plst *plst, void *content)
{
	t_plst_e	*elem;

	if (plst == NULL)
		return ;
	if (plst->first == NULL)
		return ;
	if (plst->first->content == content)
	{
		ft_plst_remove_next(&(plst->first));
		plst->size--;
		return ;
	}
	elem = plst->first;
	while (elem->next != NULL)
	{
		if (elem->next->content == content)
		{
			ft_plst_remove_next(&(elem->next));
			plst->size--;
			return ;
		}
		elem = elem->next;
	}
}
