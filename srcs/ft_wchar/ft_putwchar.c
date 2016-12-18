/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:22:34 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/05 17:10:39 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wchar.h"

void				ft_putwchar(wchar_t c)
{
	char	tab[4];

	write(1, tab, ft_sputwchar(tab, c));
}