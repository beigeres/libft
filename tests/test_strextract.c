/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strextract.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 20:29:55 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/14 20:35:05 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(int argc, char **argv)
{
	char	*str = argv[argc - 1];
	ft_printf("%d\n", ft_strchr(str, ' '));
	ft_printf("%s\n", ft_strextract(str, ' '));
	return (0);
}
