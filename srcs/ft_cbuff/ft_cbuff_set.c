/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cbuff_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 22:49:51 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/03 22:52:12 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cbuff.h"

void				ft_cbuff_set(t_cbuff *buff, char c, size_t pos, size_t n)
{
	size_t			i;

	if (buff == NULL)
		return ;
	i = 0;
	while (i < n)
	{
		((char *)(buff->buff))[(pos + i) % buff->size] = c;
		++i;
	}
}
