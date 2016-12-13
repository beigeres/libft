/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 16:44:13 by etrobert          #+#    #+#             */
/*   Updated: 2016/11/17 17:26:42 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** n is the number of characters read, '\n' excluded
*/

static int		extract(t_gnl_buff *buff, char **line,
		size_t line_size, size_t n)
{
	if ((*line = ft_nrealloc(*line, line_size,
					line_size + n + 1 + FT_GNL_EOL_ON)) == NULL)
		return (-1);
	ft_memcpy(*line + line_size, buff->buff, n);
	if (FT_GNL_EOL_ON)
		(*line)[line_size + n] = '\n';
	(*line)[line_size + n + FT_GNL_EOL_ON] = '\0';
	return (1);
}

int				get_next_line_buff(const int fd, char **line, t_gnl_buff *buff)
{
	char					*ptr;
	size_t					line_size;

	*line = NULL;
	line_size = 0;
	while ((ptr = ft_memchr(buff->buff, '\n', buff->size)) == NULL)
	{
		if (extract(buff, line, line_size, buff->size) == -1)
			return (-1);
		line_size += buff->size;
		if ((buff->size = read(fd, buff->buff, BUFF_SIZE)) == -1)
			return (-1);
		else if (buff->size == 0)
		{
			if (line_size == 0)
				return (0);
			return (FT_GNL_RET_V);
		}
	}
	if (extract(buff, line, line_size, ptr - buff->buff) == -1)
		return (-1);
	line_size += ptr - buff->buff;
	ft_memmove(buff->buff, ptr + 1, buff->size - (ptr - buff->buff + 1));
	buff->size -= ptr - buff->buff + 1;
	return (FT_GNL_RET_V);
}

static t_bool	good_fd(t_gnl_buff *buff, int *fd)
{
	return (buff->fd == *fd);
}

int				get_next_line(const int fd, char **line)
{
	static t_slist	*buffs = NULL;
	t_gnl_buff		*buff;
	int				fd_cpy;
	int				n;

	if (line == NULL)
		return (-1);
	fd_cpy = fd;
	if ((buff = (t_gnl_buff *)ft_slist_find(buffs, &fd_cpy,
					(t_comp_func)(&good_fd))) == NULL)
	{
		if ((buff = malloc(sizeof(t_gnl_buff))) == NULL)
			return (-1);
		buff->size = 0;
		buff->fd = fd;
		ft_slist_push_front(&buffs, buff);
	}
	n = get_next_line_buff(fd, line, buff);
	if (n == -1 || buff->size == 0)
	{
		free(buff);
		ft_slist_remove(&buffs, buff);
	}
	return (n);
}
