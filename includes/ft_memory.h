/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:02:35 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/05 16:02:23 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

/*
** Needed for size_t
*/

# include <stdlib.h>

typedef struct	s_memory
{
	void			*ptr;
	size_t			size;
}				t_memory;

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);

void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_memdup(const void *ptr, size_t size);
void			*ft_nrealloc(void *ptr, size_t old_size, size_t new_size);

void			ft_swap_int(int *a, int *b);

#endif
