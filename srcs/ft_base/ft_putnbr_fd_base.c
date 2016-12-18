/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 20:17:30 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/18 14:44:27 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base.h"

static void	ft_putnbr_fd_base_r(unsigned int n, int fd, t_base *base)
{
	if (n >= base->size)
		ft_putnbr_fd_base_r(n / base->size, fd, base);
	ft_putchar_fd(base->str[n % base->size], fd);
}

void		ft_putnbr_fd_base(int n, int fd, t_base *base)
{
	if (n >= 0)
	{
		ft_putnbr_fd_base_r((unsigned int)n, fd, base);
		return ;
	}
	ft_putchar_fd('-', fd);
	ft_putnbr_fd_base_r((unsigned int)-n, fd, base);
}
