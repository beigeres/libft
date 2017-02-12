/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endian.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:41:41 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/12 20:14:48 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENDIAN_H
# define FT_ENDIAN_H

# include <stdbool.h>

bool		ft_is_big_endian(void);
int			ft_int32_big_endian(int n);

#endif