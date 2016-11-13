/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:34:42 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/11 17:18:10 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_plst.h"

t_plst				*ft_plst_new(void)
{
	t_plst	*plst;

	if ((plst = (t_plst *)malloc(sizeof(t_plst))) == NULL)
		return (NULL);
	plst->first = NULL;
	plst->last = NULL;
	plst->size = 0;
	return (plst);
}

void				ft_plst_delete(t_plst *plst)
{
	t_plst_e	*elem;

	if (plst == NULL)
		return ;
	while (plst->first != NULL)
	{
		elem = plst->first->next;
		free(plst->first);
		plst->first = elem;
	}
	free(plst);
}

void			ft_plst_pop_front(t_plst *plst)
{
	t_plst_e	*todell;

	if (plst == NULL)
		return ;
	if (plst->first == NULL)
		return ;
	todell = plst->first;
	if (todell == NULL)
		plst->last = NULL;
	plst->first = plst->first->next;
	free(todell);
	plst->size--;
}
