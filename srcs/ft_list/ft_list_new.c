/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:17:49 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/26 20:34:08 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list			*ft_list_new(void)
{
	t_list	*list;

	if ((list = malloc(sizeof(*list))) == NULL)
		return (NULL);
	ft_list_init(list);
	return (list);
}
