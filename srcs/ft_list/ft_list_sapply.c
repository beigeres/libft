/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sapply.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:29:05 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/17 18:32:37 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int				ft_list_sapply(const t_list *list, t_f_sapply f)
{
	t_list_e	*cur;
	int			ret;

	if (list == NULL || f == NULL)
		return (FT_GOOD);
	cur = list->first;
	while (cur != NULL)
	{
		if ((ret = (*f)(cur->val)) != FT_GOOD)
			return (ret);
		cur = cur->next;
	}
	return (FT_GOOD);
}
