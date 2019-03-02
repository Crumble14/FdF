/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:57:45 by llenotre          #+#    #+#             */
/*   Updated: 2019/02/28 19:59:50 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_bool		is_end(const char *str)
{
	while (*str && ft_isspace(*str))
		++str;
	return (!(*str));
}

static int			get_char_val(const char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

static int			get_nbr(const char **str)
{
	long	n;
	char	neg;
	char	hexa;

	while (**str && ft_isspace(**str))
		++(*str);
	neg = (**str == '-');
	if (**str == '+' || **str == '-')
		++(*str);
	hexa = (ft_strlen(*str) >= 2 && (*str)[0] == '0' && (*str)[1] == 'x');
	if (hexa)
		(*str) += 2;
	if (!((**str >= '0' && **str <= '9') || (**str >= 'a' && **str <= 'f')
		|| (**str >= 'A' && **str <= 'F')))
		exit(-1);
	n = 0;
	while ((**str >= '0' && **str <= '9') || (**str >= 'a' && **str <= 'f')
		|| (**str >= 'A' && **str <= 'F'))
	{
		n *= (hexa ? 16 : 10);
		n += get_char_val(*((*str)++));
	}
	return (neg ? -n : n);
}

static t_wireframe	*handle_line(const char *line, int y)
{
	t_wireframe	*w;
	t_point		point;

	if (!line)
		return (NULL);
	w = NULL;
	point.x = 0;
	point.y = y;
	while (!is_end(line))
	{
		point.z = get_nbr(&line) * POINT_GAP_Z;
		join_wireframes(&w, create_wireframe(&point), 0);
		point.x += POINT_GAP;
	}
	return (w);
}

t_wireframe			*read_wireframe(const char *file)
{
	int			fd;
	char		*line;
	t_wireframe	*w;
	int			y;

	if (!file || (fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	w = NULL;
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		join_wireframes(&w, handle_line(line, y), 1);
		free((void *)line);
		y += POINT_GAP;
	}
	close(fd);
	return (w);
}
