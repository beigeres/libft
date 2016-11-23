/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 20:17:30 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/23 15:40:49 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_fd_base_r_neg(int n, int fd, int b)
{
	if (n <= -b)
		ft_putnbr_fd_base_r_neg(n / b, fd, b);
	ft_putchar_fd(-(n % b) + '0', fd);
}

static void	ft_putnbr_fd_base_r(int n, int fd, int b)
{
	if (n >= b)
		ft_putnbr_fd_base_r(n / b, fd, b);
	ft_putchar_fd(n % b + '0', fd);
}

void		ft_putnbr_fd_base(int n, int fd, int b)
{
	if (n >= 0)
	{
		ft_putnbr_fd_base_r(n, fd, b);
		return ;
	}
	ft_putchar_fd('-', fd);
	ft_putnbr_fd_base_r_neg(n, fd, b);
}
