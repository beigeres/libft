/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:50:58 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/05 17:53:00 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base.h"

t_base			*ft_base_new(const char *str, unsigned int size)
{
	t_base	*ret;

	if ((ret = malloc(sizeof(*ret))) == NULL)
		return (NULL);
	ret->str = ft_strdup(str);
	ret->size = size;
	return (ret);
}

void			ft_base_delete(t_base *base)
{
	free(base->str);
	free(base);
}
