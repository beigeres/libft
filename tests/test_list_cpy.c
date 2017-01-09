#include "libft.h"

int main(int argc, char **argv)
{
	t_list	*l1;
	t_list	*l2;
	int		i;
	t_list_it	it;

	l1 = ft_list_new();
	i = 0;
	while (i < argc)
	{
		ft_list_push_back(l1, argv[i]);
		++i;
	}
	l2 = ft_list_cpy(l1);
	it = ft_list_begin(l2);
	while (!ft_list_it_end(l2, it))
	{
		ft_printf("%s\n", ft_list_it_get(it));
		ft_list_it_inc(&it);
	}
	return (0);
}
