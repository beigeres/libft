/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 18:58:32 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/20 19:28:59 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_set.h"

t_set			*ft_set_new(t_f_compare f)
{
	t_set		*set;

	if (f == NULL)
		return (NULL);
	if ((set = (t_set *)(malloc(sizeof(t_set)))) == NULL)
		return (NULL);
	set->size = 0;
	set->root = NULL;
	set->less = f;
	return (set);
}
