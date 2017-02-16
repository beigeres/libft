/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:51:27 by mverdier          #+#    #+#             */
/*   Updated: 2017/02/16 14:51:50 by mverdier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static int			ft_word_len(const char *s, char *chars)
{
	int	n;

	n = 0;
	while (!ft_strchr(chars, s[n]) && s[n] != '\0')
		n++;
	return (n);
}

static const char	*ft_next_word(const char *s, char *chars)
{
	while (!ft_strchr(chars, *s) && *s != '\0')
		s++;
	while (ft_strchr(chars, *s) && *s != '\0')
		s++;
	return (s);
}

static char			*ft_get_word(const char *s, char *chars)
{
	char	*res;
	int		i;

	if ((res = malloc(sizeof(char) * (ft_word_len(s, chars) + 1))) == NULL)
		return (NULL);
	i = 0;
	while (!ft_strchr(chars, s[i]) && s[i] != '\0')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static int			ft_count_words(const char *s, char *chars)
{
	int	n;

	if (s == NULL)
		return (-1);
	n = 0;
	while (*s != '\0')
	{
		s = ft_next_word(s, chars);
		n++;
	}
	return (n);
}

char				**ft_strsplit_str(const char *s, char *chars)
{
	char	**tab;
	int		i;

	if (s == NULL)
		return (NULL);
	while (ft_strchr(chars, *s) && *s != '\0')
		s++;
	if ((tab = malloc(sizeof(char *) * (ft_count_words(s, chars) + 1))) == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		tab[i] = ft_get_word(s, chars);
		s = ft_next_word(s, chars);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
