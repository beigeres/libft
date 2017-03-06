/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_test_chars.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:16:42 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/06 17:19:06 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

bool			ft_str_test_chars(char *str, bool (*test)(char))
{
	while (*str != '\0')
	{
		if (!(*test)(*str))
			return (false);
		++str;
	}
	return (true);
}
