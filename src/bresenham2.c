/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:40:14 by llenotre          #+#    #+#             */
/*   Updated: 2019/02/26 16:53:13 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	bresenham2a(t_mlx_info *info, t_line *line, int dx, int dy)
{
	int e;

	e = dx;
	dx = e * 2;
	dy *= 2;
	while (TRUE)
	{
		mlx_pixel_put(info->ptr, info->win,
			line->p1.x, line->p1.y, 0xffffff);
		if (--line->p1.x == line->p2.x)
			break ;
		if ((e += dy) >= 0)
		{
			++line->p1.y;
			e += dx;
		}
	}
}

static void	bresenham2b(t_mlx_info *info, t_line *line, int dx, int dy)
{
	int e;

	e = dy;
	dy = e * 2;
	dx *= 2;
	while (TRUE)
	{
		mlx_pixel_put(info->ptr, info->win,
			line->p1.x, line->p1.y, 0xffffff);
		if (++line->p1.y == line->p2.y)
			break ;
		if ((e += dx) <= 0)
		{
			--line->p1.x;
			e += dy;
		}
	}
}

void		bresenham_quadrant2(t_mlx_info *info, t_line *line, int dx, int dy)
{
	if (-dx >= dy)
		bresenham2a(info, line, dx, dy);
	else
		bresenham2b(info, line, dx, dy);
}
