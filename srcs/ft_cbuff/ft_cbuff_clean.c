/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cbuff_clean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 22:43:28 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/03 22:43:35 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cbuff.h"

void				ft_cbuff_clean(t_cbuff *buff)
{
	if (buff == NULL)
		return ;
	ft_bzero(buff->buff, buff->size);
}
