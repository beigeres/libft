/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:25:20 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/15 19:01:23 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void			*ft_list_back(const t_list *list)
{
	if (list == NULL)
		return (NULL);
	if (list->last == NULL)
		return (NULL);
	return (list->last->val);
}
