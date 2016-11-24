/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:41:18 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/24 15:42:07 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int						ft_max(int a, int b)
{
	return ((a > b) ? a : b);
}


int						ft_min(int a, int b)
{
	return ((a < b) ? a : b);
}

unsigned int			ft_umax(unsigned int a, unsigned int b)
{
	return ((a > b) ? a : b);
}

unsigned long long int	ft_llabs(long long int n)
{
	return ((n < 0) ? -n : n);
}
