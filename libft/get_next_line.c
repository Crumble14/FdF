/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:10:19 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/22 19:19:10 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strextend(const char *dst, const char *src)
{
	size_t	len1;
	size_t	len2;
	char	*buffer;

	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	if (!(buffer = ft_strnew(len1 + len2)))
		return (NULL);
	ft_memcpy(buffer, dst, len1);
	free((void*)dst);
	ft_memcpy(buffer + len1, src, len2);
	return (buffer);
}

static char	*ft_read(char *tmp, const int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		len;

	while ((len = read(fd, buff, BUFF_SIZE)))
	{
		buff[len] = '\0';
		if (!(tmp = ft_strextend(tmp, buff)))
			return (NULL);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (tmp);
}

static int	ft_get_line(char **tmp, char **line)
{
	size_t i;
	size_t j;

	if (**tmp == '\0')
		return (0);
	i = 0;
	while ((*tmp)[i] && (*tmp)[i] != '\n')
		++i;
	*line = ft_strextend(*line, *tmp);
	(*line)[i] = '\0';
	if ((*tmp)[i] == '\0')
		ft_strclr(*tmp);
	else
	{
		++i;
		j = 0;
		while ((*tmp)[i + j])
			++j;
		ft_memmove(*tmp, *tmp + i, j + 1);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*tmp = NULL;

	if (!line || fd < 0 || read(fd, NULL, 0) < 0)
		return (-1);
	*line = NULL;
	if (!tmp && !(tmp = ft_strnew(0)))
		return (-1);
	if (!ft_strchr(tmp, '\n'))
	{
		if (!(tmp = ft_read(tmp, fd)))
			return (-1);
	}
	return (ft_get_line(&tmp, line));
}
