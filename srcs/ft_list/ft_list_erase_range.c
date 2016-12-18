/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_erase_range.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 18:05:35 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/18 16:16:07 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_erase_range(t_list *list, t_list_it first, t_list_it last)
{
	if (list == NULL)
		return ;
	while (first != last)
		first = ft_list_erase(list, first);
}
