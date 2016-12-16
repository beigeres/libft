/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:59:56 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/14 18:26:24 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "libft.h"

int		main(int argc, char **argv)
{
	int		i;
	t_list	*l;
	t_list_it	it;

	l = ft_list_new();
	i = 1;
	while (i < argc)
	{
		ft_list_push_back(l, argv[i]);
		i++;
	}
	it = ft_list_begin(l);
	while (it != ft_list_end(l))
	{
		printf("%s\n", (char *)ft_list_it_get(it));
		ft_list_it_inc(&it);
	}
	return (0);
}
