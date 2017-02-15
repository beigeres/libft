/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_blanks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 21:04:28 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/15 21:07:43 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static int			ft_word_len(const char *s)
{
	int	n;

	n = 0;
	while (s[n] != ' ' && s[n] != '\t' && s[n] != '\0')
		n++;
	return (n);
}

static const char	*ft_next_word(const char *s)
{
	while (*s != ' ' && *s != '\t' && *s != '\0')
		s++;
	while ((*s == ' ' || *s == '\t') && *s != '\0')
		s++;
	return (s);
}

static char			*ft_get_word(const char *s)
{
	char	*res;
	int		i;

	if ((res = malloc(sizeof(char) * (ft_word_len(s) + 1))) == NULL)
		return (NULL);
	i = 0;
	while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static int			ft_count_words(const char *s)
{
	int	n;

	if (s == NULL)
		return (-1);
	n = 0;
	while (*s != '\0')
	{
		s = ft_next_word(s);
		n++;
	}
	return (n);
}

char				**ft_strsplit_blanks(const char *s)
{
	char	**tab;
	int		i;

	if (s == NULL)
		return (NULL);
	while ((*s == ' ' || *s == '\t') && *s != '\0')
		s++;
	if ((tab = malloc(sizeof(char *) * (ft_count_words(s) + 1))) == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		tab[i] = ft_get_word(s);
		s = ft_next_word(s);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
