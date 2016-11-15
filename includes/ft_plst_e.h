/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plst_e.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:23:14 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/14 19:47:14 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PLST_E_H
# define FT_PLST_E_H

# include <string.h>
# include <stdlib.h>

typedef struct	s_plst_e
{
	void			*content;
	struct s_plst_e	*next;
}				t_plst_e;

t_plst_e	*ft_plst_e_new(void *content, t_plst_e *next);
void		ft_plst_e_push_front(t_plst_e **ptr, void *content);

#endif
