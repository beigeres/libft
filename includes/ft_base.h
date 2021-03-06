/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:03:16 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/18 16:34:43 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BASE_H
# define FT_BASE_H

/*
** Needed for uintmax_t
*/

# include <stdint.h>

# include "ft_string.h"
# include "ft_print.h"

typedef struct	s_base
{
	unsigned int	size;
	char			*str;
}				t_base;

t_base			*ft_base_new(const char *str, unsigned int size);
void			ft_base_delete(t_base *base);

void			ft_putnbr_fd_base(int n, int fd, t_base *base);
char			*ft_itoa_base(int n, unsigned int b);

unsigned int	ft_digits_base(int n, unsigned int b);
unsigned int	ft_ll_digits_base(long long int n, unsigned int b);
unsigned int	ft_uintmax_digits_base(uintmax_t n, unsigned int base);

void			ft_sputll_dig(long long int n, t_base *base, char *str,
		unsigned int digits);
void			ft_sputull_dig(unsigned long long int n, t_base *base,
		char *str, unsigned int digits);

void			ft_sputuintmax_dig(uintmax_t n, t_base *base,
		char *str, unsigned int digits);

#endif
