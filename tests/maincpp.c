// erasing from list
#include "libft.h"

int	*getint(int c)
{
	int	*ret;

	ret = malloc(sizeof(int));
	*ret = c;
	return (ret);
}

void	printlist(t_list *mylist)
{
	t_list_it	it1;

	ft_printf("mylist contains:");
	for (it1 = ft_list_begin(mylist); !ft_list_end(mylist, it1); ft_list_it_inc(&it1))
		ft_printf(" %d\n", *(int *)ft_list_it_get(it1));
}

int main ()
{
	t_list		*mylist;
	t_list_it	it1, it2;

	mylist = ft_list_new();
	// set some values:
	for (int i=1; i<10; ++i) ft_list_push_back(mylist, getint(i*10));

								// 10 20 30 40 50 60 70 80 90
	it1 = it2 = ft_list_begin(mylist); // ^^
	ft_list_it_advance(&it2, 6);            // ^                 ^
	ft_list_it_inc(&it1);                      //    ^              ^

	it1 = ft_list_erase(mylist, it1);   // 10 30 40 50 60 70 80 90
								//    ^           ^

	it2 = ft_list_erase(mylist, it2);
	// 10 30 40 50 60 80 90
								//    ^           ^

	ft_list_it_inc(&it1);
	ft_list_it_dec(&it2);

	ft_list_erase_range(mylist, it1, it2);

	printlist(mylist);
	ft_list_clear(mylist);
	ft_printf("%d\n", ft_list_size(mylist));
	printlist(mylist);
	
	ft_list_apply(mylist, &free);

	ft_list_delete(mylist);
	return (0);
}
