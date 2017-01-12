/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_pop_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:15:30 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/10 17:23:10 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(void)
{
	t_list	*list;

	list = ft_list_new();
	ft_list_push_back(list, ft_strdup("Bonjour\n"));
	ft_list_apply(list, &ft_putstr);
	ft_list_pop_back(list);
	//ft_list_pop_back(list);
	ft_list_apply(list, &ft_putstr);
	return (0);
}
