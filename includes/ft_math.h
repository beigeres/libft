/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:37:05 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/03 18:46:22 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

/*
** Necessary for intmax_t and uintmax_t
*/

# include <stdint.h>

int						ft_min(int a, int b);
unsigned int			ft_umin(unsigned int a, unsigned int b);
int						ft_max(int a, int b);
unsigned int			ft_umax(unsigned int a, unsigned int b);
intmax_t				ft_intmaxmax(intmax_t a, intmax_t b);

int						ft_min_int(int a, int b);

unsigned long long int	ft_llabs(long long int a);
uintmax_t				ft_intmaxabs(intmax_t n);

#endif
