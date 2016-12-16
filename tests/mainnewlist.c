/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainnewlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:23:13 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/16 16:59:51 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(void)
{
	t_list	*list;
	
	ft_list_new(&ft_obj_new, &ft_obj_delete);
	ft_list_push_back(list);

	//
	
	ft_list_delete(list);
}

//size version
int main(void)
{
	t_list *list;

	list = ft_list_new(sizeof(t_obj));

	ft_list_push_back(list);
	ft_obj_init(ft_list_back(list));

	//
	
	ft_list_apply(list, &ft_clear_obj);
	ft_list_delete(list);
}

//liste d'int
int main(void)
{
	t_list	*list;
	
	list = ft_list_new(sizeof(int));
	ft_list_push_back(list, 3);

	//
	
	ft_list_delete(list);
}
