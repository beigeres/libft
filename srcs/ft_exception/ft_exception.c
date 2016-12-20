#include "ft_exception.h"

#include <stdio.h>

int	ft_exception(int error)
{
	static jmp_buf	buf;
	int	n;

	if (error == 0)
	{
		n = (setjmp(buf));
		printf("je renvois %d\n", n);
		return (n);
	}
	longjmp(buf, error);
	return (8);
}
