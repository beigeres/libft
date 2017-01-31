/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:59:56 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/29 18:25:21 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_set(t_set *set);
void	print_set_nodes(t_set *set);

bool	less(char *s1, char *s2)
{
	return (ft_strcmp(s1, s2) < 0);
}

int		main(int argc, char **argv)
{
	int	i;
	t_set	*set;

	if ((set = ft_set_new((t_f_compare)&less)) == NULL)
	{
		ft_dprintf(2, "ERROR DURING FT_SET_NEW\n");
		return (-1);
	}
	i = 1;
	while (i < argc)
	{
		ft_set_insert(set, argv[i]);
		++i;
	}
	/*
	t_set_it	it;
	it = ft_set_begin(set);
	while (!ft_set_it_end(set, it))
	{
		ft_printf("%s\n", ft_set_it_get(set, it));
		it = ft_set_it_next(it);
	}
	*/
//	print_set(set);
	print_set_nodes(set);
	ft_set_rotate_left(set, set->root);
	ft_printf("\n");
	print_set_nodes(set);
//	print_set(set);
	return (0);
}
