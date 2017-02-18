/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cbuff_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 20:37:02 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/18 20:37:57 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cbuff.h"

void				ft_cbuff_delete(t_cbuff *buff)
{
	if (buff == NULL)
		return ;
	free(buff->buff);
	free(buff);
}
