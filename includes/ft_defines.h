/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_defines.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:13:36 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/26 21:11:03 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEFINES_H
# define FT_DEFINES_H

# include <stdlib.h>

# define FT_ERROR 1
# define FT_GOOD 0

typedef bool			(*t_f_compare)(void *, void *);
typedef void			(*t_f_apply)(void *);
typedef size_t			t_size_type;
typedef unsigned int	t_distance;
typedef int				t_errcode;

#endif
