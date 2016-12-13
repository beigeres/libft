/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:34:16 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/13 16:36:55 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALLOC_H
# define FT_ALLOC_H

# include <stdlib.h>
# include "ft_memory.h"

void			*ft_nrealloc(void *ptr, size_t old_size, size_t new_size);

#endif
