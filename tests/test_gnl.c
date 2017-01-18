/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 16:41:48 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/18 17:20:35 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(void)
{
	int		n;
	char	*str;

	while ((n = ft_get_section(0, &str, '\n')) > 0)
	{
		ft_printf("n=%d: %s\n", n, str);
		free(str);
	}
	//Should not be there
//	free(str);
	return (0);
}
