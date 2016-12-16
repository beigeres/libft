/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_e_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:08:28 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/14 16:09:55 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list_e	*ft_list_e_new(void *val, t_list_e *prev, t_list_e *next)
{
	t_list_e	*elem;

	if ((elem = malloc(sizeof(*elem))) == NULL)
		return (NULL);
	elem->val = val;
	elem->prev = prev;
	elem->next = next;
	return (elem);
}
