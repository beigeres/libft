/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:59:56 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/15 18:04:46 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "libft.h"

void	f(char *str)
{
	ft_printf("%s ", str);
}

void	farabe(t_list *list)
{
	t_list_it	it;
	static char	str[] = "gentil";

	it = ft_list_begin(list);
	while (it != ft_list_end(list))
	{
		while (ft_strcmp(ft_list_it_get(it), "arabe") == 0)
		{
			it = ft_list_erase(list, it);
			//ft_list_insert(list, it, str);
		}
		ft_list_it_inc(&it);
	}
}

int		main(int argc, char **argv)
{
	t_list	*list;
	int		i;

	list = ft_list_new();
	i = 1;
	while (i < argc)
	{
		ft_list_push_back(list, argv[i]);
	//	ft_printf("la taille est de %d\n", ft_list_size(list));
		i++;
	}
	farabe(list);
	ft_list_apply(list, (t_f_apply)&f);
	return (0);
}
