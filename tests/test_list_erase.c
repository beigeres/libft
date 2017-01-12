/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_erase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:08:41 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/12 11:18:40 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(int argc, char **argv)
{
	t_list	*list;
	int		i;

	list = ft_list_new();
	i = 0;
	while (i < argc)
	{
		ft_list_push_back(list, argv[i]);
		++i;
	}

	t_list_it	it;

	it = ft_list_begin(list);
	while (!ft_list_it_end(list, it))
	{
		ft_printf("Je suis %s\n", (char *)(ft_list_it_get(list, it)));
		it = ft_list_erase(list, it);
	}
	it = ft_list_begin(list);
	while (!ft_list_it_end(list, it))
	{
		ft_printf("Je suis %s\n", (char *)(ft_list_it_get(list, it)));
		it = ft_list_erase(list, it);
	}
	/*
	ft_list_erase(list, ft_list_find(list, argv[0]));
	ft_printf("Je suis : %p\n", (char *)(ft_list_it_get(list, ft_list_find(list, argv[0]))));
	ft_list_apply(list, (t_f_apply)(&ft_putstr));
	*/
	return (0);
}
