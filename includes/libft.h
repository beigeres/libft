/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:41:17 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/18 15:54:41 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "ft_bool.h"
# include "ft_hlist.h"
# include "ft_slist.h"
# include "ft_printf.h"
# include "ft_base.h"
# include "ft_math.h"
# include "ft_string.h"
# include "ft_char_tools.h"
# include "ft_wchar.h"
# include "get_next_line.h"
# include "ft_list.h"
# include "ft_print.h"

/*
typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

** Libft lists

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *elem);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			*ft_lstfold(t_list *lst, void *(*f)(void *, void *));
*/

#endif
