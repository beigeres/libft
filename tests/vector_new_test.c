/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:59:56 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/19 19:25:10 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "ft_vector.h"

int		main(int argc, char **argv)
{
	t_vector	*vec;
	int			i;
	int			n;

	n = 45;
	vec = ft_vector_new_size(sizeof(int), 0);
	printf("capcity is %d\n", ft_vector_capacity(vec));
	i = 0;
	while (i < n)
	{
		ft_vector_push_back(vec);
		*(int *)ft_vector_back(vec) = i;
	//	printf("adding %d: capcity is %d\n", i, ft_vector_capacity(vec));
		i++;
	}
	i = n - 1;
	while (i >= 0)
	{
		printf("%d\n", *(int *)ft_vector_at(vec, i));
		i--;
	}
	printf("Back is : %d\n", *(int *)ft_vector_back(vec));
	printf("front is : %d\n", *(int *)ft_vector_front(vec));
	return (0);
}
