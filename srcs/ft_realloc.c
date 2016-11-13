/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 19:01:25 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/13 19:09:38 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_nrealloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*ret;

	if ((ret = malloc(new_size)) == NULL)
		return (NULL);
	ft_memcpy(ret, ptr, old_size);
	return (ret);
}
