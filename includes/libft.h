/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:41:17 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/16 19:27:07 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** Needed for NULL declaration
*/

# include <string.h>

/*
** Needed for write declaration ft_putchar...
*/

# include <unistd.h>

/*
** Needed for malloc declaration
*/

# include <stdlib.h>

/*
** Needed for variadic function ft_printf
*/

# include <stdarg.h>

# include "ft_bool.h"
# include "ft_hlist.h"
# include "ft_slist.h"
# include "ft_printf.h"
# include "ft_base.h"
# include "ft_math.h"
# include "ft_string.h"
# include "ft_char_tools.h"
# include "ft_wchar.h"
# include "ft_alloc.h"
# include "get_next_line.h"
# include "ft_list.h"

/*
typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;
*/

int				ft_atoi(const char *str);

char			*ft_itoa(int n);

void			ft_putchar(char c);
void			ft_putstr(const char *str);
void			ft_putendl(const char *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putendl_fd(const char *str, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
** Libft lists

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *elem);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
*/

/*
** Individual Part
*/

int				ft_isblank(int c);
int				ft_isspace(int c);

void			*ft_lstfold(t_list *lst, void *(*f)(void *, void *));

#endif
