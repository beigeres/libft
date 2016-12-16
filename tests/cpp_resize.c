#include "libft.h"
// resizing list

int main ()
{
	t_list	*mylist;
	int		*n;

	mylist = ft_list_new();
	// set some initial content:
	for (int i=1; i<10; ++i)
	{
		n = ft_memdup(&i, sizeof(int));
		ft_list_push_back(mylist, &i);
		ft_list_push_back(mylist, n);
	}

	ft_list_resize(mylist, 5);
	n = malloc(sizeof(int));
	*n = 100;
	ft_list_resize_to(mylist, 8, n);
	ft_list_resize(mylist, 12);

	ft_printf("mylist contains:");
	for (t_list_it it=ft_list_begin(mylist); !ft_list_it_end(mylist, it); ft_list_it_inc(&it))
		ft_printf(" %d", *(int *)ft_list_it_get(it));

	ft_printf("\n");
	return 0;
}


mylist.push_back();
mylist.push_back(5);

ft_list_push_back(mylist);
ft_list_push_back(mylist, 5);

ft_voiture_new();
ft_voiture_new(4, 6, 3, 5, 6, 67,7);

ft_list_push_back(mylist);
ft_list_push_back(mylist, 4);
ft_list_push_back(t_list *list, void *ref);
