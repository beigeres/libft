/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 20:17:30 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/22 19:20:38 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_fd_base_r(int n, int fd, int b)
{
	if ((n >= 0 && n >= b) || (n < 0 && n <= -b))
		ft_putnbr_fd_base_r(n / b, fd, b);
	ft_putchar_fd(((n < 0) ? -1 : 1) * (n % b) + '0', fd);
}

void		ft_putnbr_fd_base(int n, int fd, int b)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_putnbr_fd_base_r(n, fd, b);
}
