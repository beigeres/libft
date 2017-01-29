/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:55:26 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/27 19:56:08 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_slist.h"

t_slist		*ft_slist_new(void *content)
{
	t_slist	*list;

	if ((list = (t_slist *)malloc(sizeof(*list))) == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
