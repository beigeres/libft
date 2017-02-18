/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cbuff.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 20:33:24 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/18 20:47:19 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBUFF_H
# define CBUFF_H

#include <stdlib.h>

typedef struct		s_cbuff
{
	void			*buff;
	size_t			size;
}					t_cbuff;

t_cbuff				*ft_cbuff_new(size_t size);
void				ft_cbuff_delete(t_cbuff *buff);

void				ft_cbuff_memcpy(t_cbuff *dest, t_cbuff *src,
		size_t pos_dest, size_t pos_src, size_t n);
void				ft_cbuff_move(t_cbuff *dest, size_t pos_src,
		size_t pos_dest, size_t n);
void				ft_cbuff_write(t_cbuff *dest, void *src, size_t pos,
		size_t n);
void				ft_cbuff_read(t_cbuff *src, void *dest, size_t pos,
		size_t n);

#endif
