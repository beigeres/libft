/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:17:49 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/14 16:25:37 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list			*ft_list_new(void)
{
	t_list	*list;

	if ((list = malloc(sizeof(*list))) == NULL)
		return (NULL);
	list->size = 0;
	list->first = NULL;
	list->last = NULL;
	return (list);
}
