/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_e_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 19:41:53 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/20 19:43:44 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_set.h"

t_set_e			*ft_set_e_new(void *val, t_set_e *right, t_set_e *left,
		t_set_e *parent)
{
	t_set_e		*elem;
	
	if ((elem = (t_set_e *)(malloc(sizeof(t_set_e)))) == NULL)
		return (NULL);
	elem->val = val;
	elem->right = right;
	elem->left = left;
	elem->parent = parent;
	return (elem);
}
