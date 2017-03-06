/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_tools.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:11:30 by etrobert          #+#    #+#             */
/*   Updated: 2017/03/06 17:57:11 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHAR_TOOLS_H
# define FT_CHAR_TOOLS_H

# include <stdbool.h>

typedef bool	(*t_f_charis)(char c);

bool			ft_isalpha(char c);
bool			ft_isdigit(char c);
bool			ft_isalnum(char c);
bool			ft_isascii(char c);
bool			ft_isprint(char c);
bool			ft_isblank(char c);
bool			ft_isspace(char c);

char			ft_toupper(char c);
char			ft_tolower(char c);

#endif
