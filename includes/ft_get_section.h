/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_section.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:10:59 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/18 18:18:35 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_SECTION_H
# define FT_GET_SECTION_H

/*
** get_next_line reads characters from fd using a BUFF_SIZE sized buffer
** until the next '\n' character, allocates memory to store them and makes the
** line pointer point to the allocated area.
**
** Its return value is -1 in case of failure, 0 in case of EOF or 1 otherwise
** If FT_GS_BONUS is set, its return value will be the number of
** characters read + 1 instead of 1.
*/

/*
** Needed for read
*/

# include <unistd.h>

# ifdef FT_GS_RET
#  define FT_GS_RET_V line_size + 1
# else
#  define FT_GS_RET_V 1
# endif

# ifdef FT_GS_EOL
#  define FT_GS_EOL_ON 1
# else
#  define FT_GS_EOL_ON 0
# endif

# define BUFF_SIZE 2

# include "ft_memory.h"
# include "ft_slist.h"

typedef t_bool	(*t_comp_func)(void *, void *);

typedef struct	s_gs_buff
{
	char	buff[BUFF_SIZE];
	ssize_t	size;
	int		fd;
}				t_gs_buff;

typedef struct	s_gs_params
{
	t_gs_buff	*buff;
	char		**line;
	char		c;
	int	fd;
}				t_gs_params;

int				ft_get_section(const int fd, char **line, char c);

#endif
