/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_rotate_left.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:22:10 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/29 18:34:07 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_set.h"

static void	ft_set_replace_son(t_set_e *old_son, t_set_e *new_son)
{
	if (old_son == NULL)
		return ;
	new_son->parent = old_son->parent;
	if (old_son->parent == NULL)
		return ;
	if (old_son->parent->right == old_son)
		old_son->parent->right = new_son;
	else
		old_son->parent->left = new_son;
}

static void	ft_set_rotate_left_switch_son(t_set_e *elem, t_set_e *head)
{
	if (head->left != NULL)
		head->left->parent = elem;
	elem->right = head->left;
}

void		ft_set_rotate_left(t_set *set, t_set_e *elem)
{
	t_set_e	*head;

	if (elem == NULL)
		return ;
	head = elem->right;
	if (head == NULL)
		return ;
	if (set->root == elem)
		set->root = head;
	ft_set_replace_son(elem, head);
	elem->parent = head;
	ft_set_rotate_left_switch_son(elem, head);
	head->left = elem;
}
