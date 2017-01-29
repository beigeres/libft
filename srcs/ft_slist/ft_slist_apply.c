/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_apply.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:59:27 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/27 19:59:41 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_slist.h"

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
