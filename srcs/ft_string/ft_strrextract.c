/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrextract.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:32:41 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/13 15:33:00 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char			*ft_strrextract(char *str, char c)
{
	char		*ptr;

	if ((ptr = ft_strrchr(str, c)) == NULL)
		return (ft_strdup(str));
	return (ft_strsub(str, 0, ptr - str));
}
