#include <stdio.h>
#include "libft.h"

void	func(void *ptr)
{
	printf("%p\n", ptr);
}

int main(void)
{
	t_vector		*tab_int;
	int				*elem;
	int				value;

	tab_int = ft_vector_new(sizeof(int));

	value = 5;
	ft_vector_push_back_cpy(tab_int, &value);
	ft_vector_push_back_cpy(tab_int, &value);
	ft_vector_push_back_cpy(tab_int, &value);
	ft_vector_push_back_cpy(tab_int, &value);
	ft_vector_push_back_cpy(tab_int, &value);
	ft_vector_push_back_cpy(tab_int, &value);
	ft_vector_push_back_cpy(tab_int, &value);
	ft_vector_push_back_cpy(tab_int, &value);
//	ft_vector_push_back(tab_int);
	elem = (int *)ft_vector_back(tab_int);
	*elem = 5;
	
	ft_vector_push_back(tab_int);
	elem = (int *)ft_vector_back(tab_int);
	*elem = 8;

	ft_vector_push_back(tab_int);
	elem = (int *)ft_vector_back(tab_int);
	*elem = 6;

	int i = 0;
	while (i < ft_vector_size(tab_int))
	{
		elem = (int *)ft_vector_at(tab_int, i);
		ft_printf("%k%d%k", FMT_GREEN, *elem, FMT_RESET);
		i++;
	}
	ft_vector_delete(tab_int);
	return (0);
}
