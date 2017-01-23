/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 19:00:19 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/23 16:54:02 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_set.h"

/*
** ft_set_insert returns :
** -1 in case of error
** 0 in case of normal behavior
** 1 if the element was already in the set
*/

static int	ft_set_insert_left(t_set_e *elem, t_f_compare less, void *val)
{
	if (elem->left != NULL)
		return (ft_set_insert_r(elem->left, less, val));
	if ((elem->left = ft_set_e_new(val, NULL, NULL, elem)) == NULL)
		return (-1);
	return (0);
}

static int	ft_set_insert_right(t_set_e *elem, t_f_compare less, void *val)
{
	if (elem->right != NULL)
		return (ft_set_insert_r(elem->right, less, val));
	if ((elem->right = ft_set_e_new(val, NULL, NULL, elem)) == NULL)
		return (-1);
	return (0);
}

int			ft_set_insert_r(t_set_e *elem, t_f_compare less, void *val)
{
	if ((*less)(val, elem->val))
		return (ft_set_insert_left(elem, less, val));
	if ((*less)(elem->val, val))
		return (ft_set_insert_right(elem, less, val));
	return (1);
}

int			ft_set_insert(t_set *set, void *val)
{
	int		n;

	if (set == NULL)
		return (0);
	if (set->size == 0)
	{
		if ((set->root = ft_set_e_new(val, NULL, NULL, NULL)) == NULL)
			return (-1);
		++set->size;
		return (0);
	}
	if ((n = ft_set_insert_r(set->root, set->less, val)) == 0)
		++set->size;
	return (n);
}
