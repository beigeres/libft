/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_cpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 20:12:52 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/26 21:09:58 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int 			main(int argc, char **argv)
{
	t_list		*l1;
	t_list		*l2;
	int			i;
	t_list_it	it;

	l1 = ft_list_new();
	i = 0;
	while (i < argc)
	{
		l1->push_back(l1, argv[i]);
		++i;
	}
	l2 = l1->cpy(l1);
	l1->free(l1);
	it = l2->begin(l2);
	while (!l2->it_end(l2, it))
	{
		ft_printf("%s\n", l2->it_get(l2, it));
		ft_list_it_inc(&it);
	}
	l2->free(l2);
	return (0);
}
