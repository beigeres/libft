/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 19:46:34 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/18 14:44:44 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base.h"

static void	ft_itoa_base_f(unsigned int n, unsigned int b,
		char *str, unsigned int i)
{
	while (n >= b)
	{
		str[i] = (n % b) + '0';
		i--;
		n /= b;
	}
	str[i] = (n % b) + '0';
}

char		*ft_itoa_base(int n, unsigned int b)
{
	char			*str;
	unsigned int	i;

	i = ft_digits_base(n, b);
	if ((str = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	str[i] = '\0';
	i--;
	if (n < 0)
	{
		str[0] = '-';
		ft_itoa_base_f(-(unsigned int)n, b, str, i);
	}
	else
		ft_itoa_base_f((unsigned int)n, b, str, i);
	return (str);
}
