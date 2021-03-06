/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_apply.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:48:27 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/12 10:59:26 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void			ft_list_apply(const t_list *list, t_f_apply f)
{
	t_list_e	*cur;

	if (list == NULL || f == NULL)
		return ;
	cur = list->first;
	while (cur != NULL)
	{
		(*f)(cur->val);
		cur = cur->next;
	}
}
