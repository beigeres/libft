/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 16:43:01 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/13 16:38:02 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
** get_next_line reads characters from fd using a BUFF_SIZE sized buffer
** until the next '\n' character, allocates memory to store them and makes the
** line pointer point to the allocated area.
**
** Its return value is -1 in case of failure, 0 in case of EOF or 1 otherwise
** If FT_GNL_BONUS is set, its return value will be the number of
** characters read + 1 instead of 1.
*/

/*
** Needed for read
*/

# include <unistd.h>

# ifdef FT_GNL_RET
#  define FT_GNL_RET_V line_size + 1
# else
#  define FT_GNL_RET_V 1
# endif

# ifdef FT_GNL_EOL
#  define FT_GNL_EOL_ON 1
# else
#  define FT_GNL_EOL_ON 0
# endif

# define BUFF_SIZE 2

# include "ft_memory.h"
# include "ft_slist.h"
# include "ft_alloc.h"

typedef t_bool	(*t_comp_func)(void *, void *);

typedef struct	s_gnl_buff
{
	char	buff[BUFF_SIZE];
	ssize_t	size;
	int		fd;
}				t_gnl_buff;

int				get_next_line(const int fd, char **line);

#endif
