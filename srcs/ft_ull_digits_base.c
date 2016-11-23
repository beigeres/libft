#include "libft.h"

unsigned int	ft_ull_digits_base(unsigned long long int n, unsigned int base)
{
	int	a;

	a = 1;
	while (n >= (unsigned long long int)base)
	{
		a++;
		n /= base;
	}
	return (a);
}
