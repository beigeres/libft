#include "libft.h"
#include "ft_exception.h"
#include <stdio.h>
/*
jmp_buf	buf;

int main(void)
{
	int	n;

	if ((n = setjmp(buf)) == 0)
	{
		printf("Code sensible\n");
		longjmp(buf, 1);
		printf("Je nexiste pas\n");
	}
	else
		printf("ERREUR :%d\n", n);
	return (0);
}*/

int main(void)
{
	int n;

	if ((n = ft_exception(0)) == 0)
	{
		ft_printf("Code sensible\n");
		ft_exception(1);
		ft_printf("Je nexiste pas n = %d\n", n);
	}
	else
		ft_printf("ERREUR : %d\n", n);
	return (0);
}
