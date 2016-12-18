/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_tools.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:11:30 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/18 14:53:52 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHAR_TOOLS_H
# define FT_CHAR_TOOLS_H

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii (int c);
int	ft_isprint(int c);
int	ft_isblank(int c);
int	ft_isspace(int c);

int	ft_toupper(int c);
int	ft_tolower(int c);

#endif
