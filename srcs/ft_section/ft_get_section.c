/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_section.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:13:08 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/18 17:32:53 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_section.h"

/*
** n is the number of characters read, c excluded
*/

static int		extract(t_gs_params *pa, size_t line_size, size_t n)
{
	if ((*(pa->line) = ft_nrealloc(*(pa->line), line_size,
					line_size + n + 1 + FT_GS_EOL_ON)) == NULL)
		return (-1);
	ft_memcpy(*(pa->line) + line_size, pa->buff->buff, n);
	if (FT_GS_EOL_ON)
		(*(pa->line))[line_size + n] = pa->c;
	(*(pa->line))[line_size + n + FT_GS_EOL_ON] = '\0';
	return (1);
}

int				get_section_buff(t_gs_params *pa)
{
	char					*ptr;
	size_t					line_size;

	line_size = 0;
	while ((ptr = ft_memchr(pa->buff->buff, pa->c, pa->buff->size)) == NULL)
	{
		if (pa->line != NULL && extract(pa, line_size, pa->buff->size) == -1)
			return (-1);
		line_size += pa->buff->size;
		if ((pa->buff->size = read(pa->fd, pa->buff->buff, BUFF_SIZE)) == -1)
			return (-1);
		else if (pa->buff->size == 0)
		{
			if (line_size == 0)
				return (0);
			return (FT_GS_RET_V);
		}
	}
	if (pa->line != NULL && extract(pa, line_size, ptr - pa->buff->buff) == -1)
		return (-1);
	line_size += ptr - pa->buff->buff;
	ft_memmove(pa->buff->buff, ptr + 1,
			pa->buff->size - (ptr - pa->buff->buff + 1));
	pa->buff->size -= ptr - pa->buff->buff + 1;
	return (FT_GS_RET_V);
}

static bool		good_fd(t_gs_buff *buff, int *fd)
{
	return (buff->fd == *fd);
}

int				ft_get_section_pa(t_gs_params *pa)
{
	static t_slist	*buffs = NULL;
	int				fd_cpy;
	int				n;

	fd_cpy = pa->fd;
	if ((pa->buff = (t_gs_buff *)ft_slist_find(buffs, &fd_cpy,
					(t_comp_func)(&good_fd))) == NULL)
	{
		if ((pa->buff = malloc(sizeof(t_gs_buff))) == NULL)
			return (-1);
		pa->buff->size = 0;
		pa->buff->fd = pa->fd;
		ft_slist_push_front(&buffs, pa->buff);
	}
	n = get_section_buff(pa);
	if (n == 0)
		free(*(pa->line));
	else if (n == -1 || pa->buff->size == 0)
	{
		free(pa->buff);
		ft_slist_remove(&buffs, pa->buff);
	}
	return (n);
}

int				ft_get_section(const int fd, char **line, char c)
{
	t_gs_params	pa;

	pa.fd = fd;
	pa.line = line;
	if (pa.line != NULL)
		*(pa.line) = NULL;
	pa.c = c;
	return (ft_get_section_pa(&pa));
}
