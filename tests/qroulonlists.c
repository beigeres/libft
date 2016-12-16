/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:59:56 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/14 20:49:43 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct	s_buff
{
	char	buffer[60];
	int		nb_char;
}				t_buff;

t_buff	*ft_buff_new(void)
{
	t_buff *t;

	t = malloc(sizeof(*t));
	t->nb_char = 0;
	return (t);
}

int	*ft_int_new(void)
{
	return (malloc(sizeof(int)));
}

t_voiture **ft_ptr_voiture_new()
{
	return (malloc(sizeof(t_voiture *)));
}

int		main(int argc, char **argv)
{
	t_list		*lst;
	t_buff		*ptr;
	t_voitures	tab[6];

	lst = ft_list_new(&ft_ptr_voiture_new);

	ft_list_push_back(lst);
	(*(t_voiture**) ft_list_back(lst)) = tab;

	(t_buff*)ft_list_back(lst).buff = uh;

	ptr = ft_list_back(lst);
	ptr->buff[0] = 'c';

	printf("%d\n", func(argv[1]));
	return (0);
}

int main(void)
{
	t_list	*list;

	list = ft_list_new(&ft_int_new, &free);
	ft_list_push_back(list, 89);
	(*ft_list_back(list)) = 90;
}
