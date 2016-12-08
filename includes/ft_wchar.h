/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:09:20 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/07 16:20:27 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <wchar.h>

unsigned int	ft_wchar_bits(wchar_t c);
void			ft_putwchar(wchar_t c);
size_t			ft_sputwchar(char *str, wchar_t c);
unsigned int	ft_wchar_dig(wchar_t c);

size_t			ft_sputwstr(char *str, const wchar_t *src);
