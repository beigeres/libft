/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_section.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:22:31 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/18 18:22:03 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int main(int ac, char **av)
{
	int		fd;
	char	*str;
	int		n;

	if ((fd = open(av[ac - 1], O_RDONLY)) < 0)
		return (EXIT_FAILURE);
	while ((n = ft_get_section(fd, &str, ';')) > 0)
//	while ((n = get_next_line(fd, &str)) > 0)
	{
		printf("n=%4d:%s\n", n, str);
		free(str);
	}
}
