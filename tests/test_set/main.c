/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:59:56 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/23 18:43:09 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_sep(int off)
{
	int	i;

	if (off == 0)
		return ;
	i = 0;
	while (i < off)
	{
		ft_printf("--");
		++i;
	}
	ft_printf(" ");
}

void	print_set_r(t_set_e *elem, int off)
{
	print_sep(off);
	if (elem == NULL)
	{
		ft_printf("NULL\n");
		return ;
	}
	ft_printf("%s\n", (char *)elem->val);
	print_set_r(elem->left, off + 1);
	print_set_r(elem->right, off + 1);
}

void	print_set(t_set *set)
{
	print_set_r(set->root, 0);
}

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
	t_set_it	it;
	it = ft_set_begin(set);
	while (!ft_set_it_end(set, it))
	{
		ft_printf("%s\n", ft_set_it_get(set, it));
		it = ft_set_it_next(it);
	}
	print_set(set);
	return (0);
}
