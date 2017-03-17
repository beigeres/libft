/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:19:59 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/17 16:50:23 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

/*
** Needed for NULL
*/

# include <string.h>

/*
** Needed for malloc
*/

# include <stdlib.h>
# include <stdbool.h>

# include "ft_memory.h"
# include "ft_base.h"
# include "ft_char_tools.h"

char			*ft_strnew(size_t size);
void			ft_strdel(char **as);

size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *str);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *s1, const char *s2, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

void			ft_strclr(char *s);
void			ft_striter(char *s, void(*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strextract(char *str, char c);
char			*ft_strrextract(char *str, char c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);

char			**ft_strsplit(const char *s, char c);
char			**ft_strsplit_str(const char *s, char *chars);

bool			ft_str_test_chars(char *str, bool (*test)(char));
bool			ft_isnumber(char *str);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);

#endif
