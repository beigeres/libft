/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strextract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 19:41:53 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/14 20:36:20 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char			*ft_strextract(char *str, char c)
{
	char		*ptr;

	if ((ptr = ft_strchr(str, c)) == NULL)
		return (ft_strdup(str));
	return (ft_strsub(str, 0, ptr - str));
}
