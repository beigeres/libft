/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:37:05 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/25 16:16:00 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

/*
** Necessary for intmax_t and uintmax_t
*/

# include <stdint.h>

int						ft_min(int a, int b);
int						ft_max(int a, int b);
unsigned int			ft_umax(unsigned int a, unsigned int b);
intmax_t				ft_intmaxmax(intmax_t a, intmax_t b);

unsigned long long int	ft_llabs(long long int a);
uintmax_t				ft_intmaxabs(intmax_t n);

#endif
