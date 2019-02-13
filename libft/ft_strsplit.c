/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:57:44 by llenotre          #+#    #+#             */
/*   Updated: 2019/01/30 17:08:39 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	ft_skip(char const **s, const char c)
{
	while (**s && **s == c)
		++(*s);
}

static size_t		ft_split_count(char const *s, char c)
{
	size_t count;

	count = 0;
	while (*s)
	{
		ft_skip(&s, c);
		if (!(*s))
			break ;
		++count;
		while (*s && *s != c)
			++s;
	}
	return (count);
}

static size_t		ft_split_size(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] && s[i] != c)
		++i;
	return (i);
}

static int			alloc(char **arr, const size_t len, size_t i)
{
	if (!(arr[i] = (char*)malloc(len + 1)))
	{
		while (i > 0)
			free((void*)arr[i-- - 1]);
		return (FALSE);
	}
	return (TRUE);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t	count;
	char	**arr;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	count = ft_split_count(s, c);
	if (!(arr = (char**)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	i = 0;
	while (*s && i < count)
	{
		ft_skip(&s, c);
		len = ft_split_size(s, c);
		alloc(arr, len, i);
		ft_strncpy(arr[i], s, len);
		arr[i][len] = '\0';
		s += len;
		++i;
	}
	arr[i] = 0;
	return (arr);
}
