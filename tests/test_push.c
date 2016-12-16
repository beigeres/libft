/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:59:56 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/14 17:28:53 by etrobert         ###   ########.fr       */
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

	l = ft_list_new();
	i = 0;
	while (i < argc)
	{
		ft_list_push_back(l, argv[i]);
		i++;
	}
	t_list_e	*e = l->first;
	while (e != NULL)
	{
		printf("%s\n", (char *)e->val);
		e = e->next;
	}
	printf("\n\n");
	e = l->last;
	while (e != NULL)
	{
		printf("%s\n", (char *)e->val);
		e = e->prev;
	}
	return (0);
}
