
int main(void)
{
	t_obj	*obj;
	t_list	*list;

	list = ft_list_new();
	if ((obj = ft_obj_new()) == NULL)
		return (-1);
	ft_list_push_back(list, obj);

	//

	ft_list_apply(list, &ft_obj_delete);
	ft_list_delete(list);
	return (0);
}

//liste d'int
int main(void)
{
	t_list *list;
	int	*n;

	list = ft_list_new();
	n = 
	ft_list_push_back
