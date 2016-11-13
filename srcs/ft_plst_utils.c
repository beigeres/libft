/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plst_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:11:21 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/13 20:23:20 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_plst.h"

void	ft_plst_apply(t_plst *plst, void (*f)(void *))
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

int		ft_plst_count_if(t_plst *plst, t_bool (*f)(void *))
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

void	*ft_plst_find(t_plst *plst, t_bool (*f)(void *))
{
	t_plst_e	*elem;

	if (plst == NULL)
		return (NULL);
	elem = plst->first;
	while (elem != NULL)
	{
		if ((*f)(elem->content))
			return (elem->content);
		elem = elem->next;
	}
	return (NULL);
}
