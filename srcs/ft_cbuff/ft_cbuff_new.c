/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cbuff_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 20:34:51 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/18 20:47:19 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cbuff.h"

t_cbuff				*ft_cbuff_new(size_t size)
{
	t_cbuff			*buff;

	if ((buff = (t_cbuff *)(malloc(sizeof(t_cbuff)))) == NULL)
		return (NULL);
	if ((buff->buff = malloc(size)) == NULL)
	{
		free(buff);
		return (NULL);
	}
	buff->size = size;
	return (buff);
}
