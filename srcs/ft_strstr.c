/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 22:49:28 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/01 17:37:00 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	j;

	if (*big == '\0' && *little == '\0')
		return ((char*)big);
	while (*big != '\0')
	{
		j = 0;
		while (big[j] == little[j] && little[j] != '\0')
			j++;
		if (little[j] == '\0')
			return ((char*)big);
		big++;
	}
	return (NULL);
}
