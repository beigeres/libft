/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:29:16 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/01 17:21:50 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	ft_memset(str, '\0', size + 1);
	return (str);
}
