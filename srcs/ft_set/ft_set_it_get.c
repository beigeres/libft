/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_it_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:40:11 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/23 17:41:07 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_set.h"

void			*ft_set_it_get(const t_set *set, t_set_it it)
{
	(void)set;
	if (it == NULL)
		return (NULL);
	return (it->val);
}
