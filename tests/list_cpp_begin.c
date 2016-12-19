// list::begin
#include <stdio.h>
#include "ft_list.h"

int main ()
{
	int myints[] = {75,23,65,42,13};
	
	printf("Bonjour" " les " "amis");
	
	t_list	*mylist;
	t_list_it	it;

	mylist = ft_list_new();
	ft_list_push_back(mylist, myints);
	ft_list_push_back(mylist, myints + 1);
	ft_list_push_back(mylist, myints + 2);
	ft_list_push_back(mylist, myints + 3);
	ft_list_push_back(mylist, myints + 4);

	printf("mylist contains:");
	for (it= ft_list_begin(mylist); ! ft_list_it_end(mylist, it); ft_list_it_inc(&it))
		printf(" %d\n", *(int *)ft_list_it_get(it));
	printf("\n");
	return 0;
}
