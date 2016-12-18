/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:09:20 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/18 15:25:18 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WCHAR_H
# define FT_WCHAR_H

# include <unistd.h>
# include <wchar.h>

unsigned int	ft_wchar_bits(wchar_t c);
void			ft_putwchar(wchar_t c);
size_t			ft_sputwchar(char *str, wchar_t c);
unsigned int	ft_wchar_dig(wchar_t c);

#endif
