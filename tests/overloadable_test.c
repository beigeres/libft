/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:59:56 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/19 21:39:55 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "libft.h"

typedef struct		s_voiture
{
	int roues;
}					t_voiture;

//int	__attribute__((overloadable))deux(int i)


//t_voiture	__attribute__((overloadable)) *ft_voiture_new(void);
//t_voiture	__attribute__((overloadable)) *ft_voiture_new(int roues);

t_voiture	__attribute__((overloadable)) *ft_voiture_new(void)
{
	t_voiture	*voi;

	if ((voi = malloc(sizeof(t_voiture))) == NULL)
		return (NULL);
	voi->roues = 4;
	return (voi);
}

t_voiture	__attribute__((overloadable)) *ft_voiture_new(int roues)
{
	t_voiture	*voi;

	if ((voi = malloc(sizeof(t_voiture))) == NULL)
		return (NULL);
	voi->roues = roues;
	return (voi);
}

int		main(int argc, char **argv)
{
	t_voiture *voir = ft_voiture_new();
	t_list	*garage;
/*
//	garage = ft_list_new(&ft_voiture_new)

	ft_list_push_back(garage);
	ft_list_push_back(garage, 5);
	*/
	printf("%d\n", voir->roues);

	return (0);
}
