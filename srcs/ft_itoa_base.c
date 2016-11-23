/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 19:46:34 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/23 15:51:50 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoa_base_f_neg(int n, int b, char *str, int i)
{
	while (n <= -b)
	{
		str[i] = -(n % b) + '0';
		i--;
		n /= b;
	}
	str[i] = -(n % b) + '0';
}

static void	ft_itoa_base_f(int n, int b, char *str, int i)
{
	while (n >= b)
	{
		str[i] = (n % b) + '0';
		i--;
		n /= b;
	}
	str[i] = (n % b) + '0';
}

char		*ft_itoa_base(int n, int b)
{
	char	*str;
	int		i;

	i = ft_digits_base(n, b);
	if ((str = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	str[i] = '\0';
	i--;
	if (n < 0)
	{
		str[0] = '-';
		ft_itoa_base_f_neg(n, b, str, i);
	}
	else
		ft_itoa_base_f(n, b, str, i);
	return (str);
}
