/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:57:45 by llenotre          #+#    #+#             */
/*   Updated: 2019/02/13 18:44:42 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_bool	is_end(const char *str)
{
	while (*str && ft_isspace(*str))
		++str;
	return (!(*str));
}

static int		get_nbr(const char **str)
{
	long	n;
	char	neg;

	while (**str && ft_isspace(**str))
		++(*str);
	neg = (**str == '-');
	if (**str == '+' || **str == '-')
		++(*str);
	n = 0;
	while (**str >= '0' && **str <= '9')
	{
		n *= 10;
		n += *((*str)++) - '0';
	}
	return (neg ? -n : n);
}

static void		handle_line(t_list **lst, const char *line, int y)
{
	t_point	point;

	if (!lst || !line)
		return ;
	point.x = 0;
	point.y = y;
	while (!is_end(line))
	{
		point.z = get_nbr(&line);
		ft_lstadd(lst, ft_lstnew(&point, sizeof(t_point)));
		++(point.x);
	}
}

const t_list	*read_wireframe(const char *file)
{
	int		fd;
	char	*line;
	t_list	*lst;
	int		y;

	if (!file || (fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	lst = NULL;
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		handle_line(&lst, line, y);
		free((void *)line);
		++y;
	}
	close(fd);
	return (lst);
}
