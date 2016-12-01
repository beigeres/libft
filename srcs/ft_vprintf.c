/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:06:53 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/01 16:16:55 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vprintf(const char *fmt, va_list ap)
{
	return (ft_vdprintf(1, fmt, ap));
}


int		ft_vsprintf(char *str, const char *fmt, va_list ap)
{
	t_hlist			*opts;
	unsigned int	n;

	if ((opts = ft_hlist_new()) == NULL)
		return (-1);
	n = ft_pri_decrypt_format(fmt, ap, opts);
	ft_pri_print(str, fmt, opts);
	return (n);
}


// Ne peut pas appeler vsprintf car vsprintf doit calculer la taille
// et vasprintf aussi pour malloc
int		ft_vasprintf(char **ret, const char *fmt, va_list ap)
{
	t_hlist			*opts;
	unsigned int	n;

	if ((opts = ft_hlist_new()) == NULL)
		return (-1);
	n = ft_pri_decrypt_format(fmt, ap, opts);
	if ((*ret = malloc(sizeof(char) * (n + 1))) == NULL)
		return (-1);
	ft_pri_print(*ret, fmt, opts);
	return (n);
}


int		ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	char	*str;
	int		n;

	if ((n = ft_vasprintf(&str, fmt, ap)) < 0)
		return (-1);
	write(fd, str, n);
	free(str);
	return (n);
}
