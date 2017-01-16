/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:59:56 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/24 18:28:09 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <stdarg.h>

int	ft_printf(char *str, ...)
{
	va_list	ap;
	long long int n;

	va_start(ap, str);
	while (*str != '\0')
	{
		if (str[0] == ' ')
			n = (long long int)va_arg(ap, int);
		else if (str[0] == 'H')
			n = (long long int)va_arg(ap, int);
		else if (str[0] == 'h')
			n = (long long int)va_arg(ap, int);
		else if (str[0] == 'l')
			n = (long long int)va_arg(ap, long int);
		else if (str[0] == 'L')
			n = (long long int)va_arg(ap, long long int);
		else if (str[0] == 'j')
			n = (long long int)va_arg(ap, intmax_t);
		printf("str[0] = : %d; %lld\n", str[0],  n);
		str++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int	v_int;
	signed char	v_char;
	short int	v_short;
	long int	v_long;
	long long int	v_llong;
	intmax_t	v_intmax;

	v_int = -20;
	v_char = v_int;
	v_short = v_int;
	v_long = v_int;
	v_llong = v_int;
	v_intmax = v_int;
	(void)ft_printf(" HhlLj", v_int, v_char, v_short, v_long, v_llong, v_intmax);
	return (0);
}
