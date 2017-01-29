/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_pop_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:56:23 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/27 19:56:56 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_slist.h"

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
